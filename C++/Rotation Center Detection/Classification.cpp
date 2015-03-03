//Classification.cpp
#include <iostream>
#include "RotationCenter.h"

//===============================================================================
//FESEG
//Questo metodo permette di segmentare l'immagine originale in input
//determinando le regioni che presentano una simmetria
////i passi seguiti sono:
// - determinazione dei fold e raggruppamento righe
// - determinazione delle regioni e del gruppo di simmetria
// - segmentare le regioni e disegnarle sull'immagine originale
//===============================================================================
Mat RotationCenter::feSeg(Mat img,int cx,int cy)
{
    double thetaStepSize = 1.0;
    int R = min((img.rows-1)/2,(img.cols-1)/2);

    int rows = img.rows;
    int cols = img.cols;

    //Effettuo la copia dell'immagine originale che servirà
    //per tracciare su di essa le circonferenze riscontrate
    Mat original_img;
    img.copyTo(original_img);

    //Estendo i bordi per effettuare la FE e la dft
    copyMakeBorder(img, img, R, R, R, R,BORDER_CONSTANT, Scalar::all(0));

    Mat pImageFE = imageFE(img,img.cols/2,img.rows/2,thetaStepSize,R);

    string imageFE = "test_out/FE.jpg";
    if(imwrite(imageFE,pImageFE))
         cout<<"Freize-Expansion salvata con successo!"<<endl;

    //Dichiaro una copia dell'immagine FEP sulla quale traccerò
    //le bande riscontrate durante l'elaborazione
    Mat tmpFE;
	//copio la FEP ottenuta nell'immagine di prima
    pImageFE.copyTo(tmpFE);

    //Calcolo la dft sulla FEP
    Mat dft = SpectralImage(pImageFE);

    //Dichiaro un array che conterrà  l'inizio e fine di ogni banda riscontrata
    int *line_seg=new int[dft.rows + 1];
    //Azzero l'array
    memset(line_seg,0L,(dft.rows + 1)*sizeof(int));

    //Ora ho ottenuto l'immagine spettrale della FEP
    //determino un valore di inizializzazione
    //che mi servirà per determinare il numero di FOLD
    //caratterizzato dal valore massimo
    //è impostato a dft.cols/4 per non avere problemi quando
    //valutiamo il primo fold con l'intorno del precedente
    int old_fold = dft.cols/4;
    int row_counter = 0;
    //Dichiaro un array che conterrà i valori delle bande
    int band_value[dft.rows + 1];
    int fold = 0;


    //DETERMINAZIONE DEI FOLD e CONSEGUENTE RAGGRUPPAMENTO RIGHE

    for(int k = 0; k < dft.rows; k++)
        {
            //Determiniamo il fold richiamando il metodo FindFold che riceve in input
            //la k-esima riga della dft
            double *row=(double *)dft.ptr<float>(k);
            fold = FindFold(row);
            //A questo punto dobbiamo costruire le regioni e per fare ciò bisogna determinare
            //un metodo per raggruppare righe "simili" in base ad una soglia
            //di tolleranza definita dal un intorno ,+-4, dal precedente valore di fold riscontrato.
            //Se il fold attuale non è compreso nella soglia di tolleranza
            //lo consideriamo come appartenente un altra banda. Aggiorniamo old_fold poichè significa
            //che abbiamo incontrato righe aventi fold che superano l'intorno
            //e quindi abbiamo incontrato un altra banda e ricominciamo a valutare.

            //old_fold rappresenta il fold precedente
            if((fold<=(old_fold-4)) || (fold>=(old_fold+4)) )
                {
                    old_fold = fold;
                    row_counter=0;
                }

            //A questo punto abbiamo un valore di fold di riferimento compreso di tolleranza e dobbiamo
            //raggruppare le righe per determinare che siamo di fronte ad una regione
            //Per convenzione abbiamo deciso di determinare un inizio/fine banda se si incontrano
            //10 righe che hanno un fold simile

            if(row_counter == 10)
                {
                    //Se abbiamo raggiunto 10, significa che è terminata una banda
                    //Ora bisogna determinare l'indice dell ultima iterazione prima dell'entrata
                    //in questo if poichè ci servirà come indice dell'array che
                    //utilizzeremo per scandire dove inizia e finisce una banda dopo.

                    //l è l'indice dell'array line_seg
                    //k è l'indice del for, quindi indica il numero di iterazioni
                    //row_counter sarà 10 cioè il contatore di righe raggruppate
                    //l indicherà quindi l'inizio della banda riscontrata e la fine
                    //della precedente
                    int l = k - row_counter;

                    //A questo punto devo memorizzare due valori:
                    //inizio/fine di una banda e il valore del fold
                    //contenuto in quella banda. Per fare ciò utilizziamo due array:
                    //- line_seg, che indica quando ho riscontrato una nuova banda
                    //e per farlo memorizziamo 1 altrimenti 0
                    //- band_value, che conterrà il valore del fold per quella k-esima banda

                    // inserisco in line_seg 1 che indica che ho raggiunto il bordo di una banda
                    // che coinciderà ovviamente con l'inizio della banda successiva

                    line_seg[l] = 1;
                    //aggiorno il valore del fold del bordo che sarà uguale all'ultimo valore di max
                    //questo ci servirà dopo per determinare il valore medio del fold
                    //cointenuto in un range di bande raggruppate
                    band_value[l] = old_fold;
               }

            //In questo caso ancora devo raggiungere la fine della banda quindi
            // ciclando sulle righe imposto_line_seq a 0 (non ho raggruppato ancora righe sufficienti),
            // quindi o siamo appena all'inizio di una nuova banda o siamo all'interno della banda
            line_seg[k] = 0;

            //conservo il valore del fold per la k-esima riga
            band_value[k] = fold;
            //aggiorno il contatore del numero di righe raggruppate
            row_counter++;
    }

    //Imposto il valore finale per impostare la fine dell'ultima banda
    line_seg[dft.rows] = 1;

    //DETERMINAZIONE DELLE REGIONI E DEL GRUPPO DI SIMMETRIA


    //region_start e region_stop sono due array che
    //verranno utilizzati per determinare l'inizio e la fine di ogni banda
    //per poi tramite region_stop[j] disegnare ogni banda sull'immagine originale
    int region_start[R];
    int region_stop[R];
    //conterrà il numero medio di fold contenuti in un range di righe raggruppato
    int mean_region_val[R];

    //Determino le regioni segmentate cioè le bande contenenti fold simili
    int region_counter = SupportingRegion(line_seg,region_start,region_stop,mean_region_val,band_value,R);

    //Arrivati a questo punto
    //Conosciamo quante bande ci sono, da dove iniziano a dove finiscono e il
    //valore medio del fold contenuto al suo interno. Ora bisogna segmentare la FE
    //per mostrare a video le bande calcolate e Discriminare il tipo di simmetria
    //riscontrata

    Mat *segFES = new Mat[R];

//ciclo per il numero di bande riscontrate
    for(int j=0;j<region_counter;j++)
        {
            //mostro le info sulle dimensioni di ogni banda riscontrata
            cout<<"Banda "<<j + 1<<": Start alla riga: "<<region_start[j]<<", Stop alla riga: "<<region_stop[j];

            //rappresento ogni banda l immagine segmentata
            //dice quant è il size di bande, indica il numero di righe che determinano la banda
            //segFES[j] sarà grande quanto region_stop[j]-region_start[j] cioè fine meno inizio ci
            //da l'informazione sul size della porzione
            segFES[j]=Mat::zeros(region_stop[j] - region_start[j],pImageFE.cols, CV_8UC1);


            //determino la porzione
            //copi la porzione riga per riga
            int line=0;
            for(int k = region_start[j]+1; k < region_stop[j]; k++)
                {
                    tmpFE.row(k).copyTo(segFES[j].row(line));
                    line++;
                }


            //Controllo la tipologia del gruppo di simmetria
            char gruop[256];
            CheckSimmetry(gruop,segFES,j,mean_region_val);



            //SEGMENTARE LE REGIONI E DISEGNARE LE LINEE

            //Per prima cosa segmentiamo la FE, quindi per segmentarla, ci servono i valori di fine di ogni
            //banda riscontrata, questa informazione è contenuta in region_stop[j]
            //partendo dal punto di coordinate (0,region_stop[j]) tracciamo una retta che termina
            //nel punto di coordinate(pImageFE.cols,region_stop[j])

            cv::line(pImageFE,Point(0,region_stop[j]),Point(pImageFE.cols,region_stop[j]),Scalar( 255, 255, 0 ),2);

            //una volta tracciata una retta possiamo scrivere la simmetria riscontrata .

            putText(pImageFE,(string)gruop, Point(32,region_stop[j] + 16), CV_FONT_HERSHEY_PLAIN, 1,Scalar(128,128,128),2);


            //Ora bisogna disegnare le circonferenze riscontrate (questa informazione sono le bande riscontrate)
            //cioè partendo dal centro (cx,cy) stimato prima disegnare le circonferenze tramite circle
            //e successivamente inserire il testo

            //ovviamente le varie bande avranno un raggio diverso a seconda di dove terminano, quindi il valore
            //che ci interessa è la fine di ogni j-esima fanda ovvero region_stop[j].
            int r=R-region_stop[j];

            //Disegno le bande sull'immagine originale
            circle(original_img, Point(cx, cy), max(r,2), Scalar(255, 0, 0),2);
            //seno e coseno per determinare posizione per inserire bene il testo
            // il +5 serve per spostarci un po di lato per scrivere il testo, il resto sono valori di test
            //per determinare la giusta posizione
            putText(original_img,(string)gruop, Point(cx+(r+5)*cos(M_PI/4),cy+(r+5)*sin(M_PI/4)), CV_FONT_HERSHEY_PLAIN, 1, Scalar(128,128,128),2);

            cout<<" Gruppo di Simmetria: "<< gruop << endl;

    }

    //STAMPA A VIDEO

    imshow("Original image", original_img);
    imshow("Fe Bands", pImageFE);

    delete []segFES;

    return original_img;
}

//===============================================================================
//FINDFOLD
//questo metodo permette di determinare il fold della riga
//passata in input al metodo. i fold sono determinati dall'indice
//dei coefficienti, analizziamo un subset poichè nel paper indica che
//i fold utili sono valore pressocchè basso. partiamo da 3 poiche partendo da un
//valore piu basso le simmetrie riscontrate erano sbagliate, quindi abbiamo
//scelto di partire da 3 cioè da quel valore che portava risultati apprezzabili
//===============================================================================

int RotationCenter::FindFold(double *row)
{
    double max_dft=0.0;
    int fold = 0;

    //dato che il fold viene indicato dall'Indice dell'array riga (i-1)
    //il paper analizza fino ad un tot di fold negli esempi, solitamente un numero
    //sempre basso.

    //Cerco il massimo nel subset e conservo la posizione (fold)
    for(int i = 3; i < 32; i++)
        {
            if(row[i] > max_dft)
            {
                max_dft = row[i];
                fold = i;
            }
       }
    //Determino il numero di fold come da paper
    //Riferimento: 3.4.2
    fold -= 1;
    return fold;

}

//===============================================================================
//SUPPORTINGREGION
//Questo metodo permette di determinare l'inizio e la fine di ogni regione e
//il valore medio del fold contenuto nella regione.
// in output restituisce anche il numero di regioni determinate
//===============================================================================
int RotationCenter::SupportingRegion(int line_seg[],int region_start[],int region_stop[],int mean_region_val[],int band_value[],int R)
{
    int region_counter=0;

    //ciclo che utilizziamo per creare le regioni
    //l'obiettivo è quello di determinare le porzioni (inizio e fine) di ogni regione
    // e il valore medio del fold contenuto all'interno, cicliamo fino ad R
    //poichè è il valore del raggio in quanto l'ultima banda al massimo
    //sarà delimitata dal valore del raggio utilizzato per la FEP

    for(int j = 0; j < (R+1); j++)
        {
            //inizializziamo un contatore delle righe a 0
            //che utilizzeremo dopo aver determinato una regione per calcolare
            //il valore medio del fold contenuto in essa.
            int row_counter = 0;
            //Se siamo all'inizio di una banda
            if(line_seg[j] == 0)
            {
                region_start[region_counter] = j;
                //incrementiamo j per controllare se la banda termina subito dopo
                j++;
                row_counter=0;
                //mean_region_val è un array che conterrà tutti i valori medi
                mean_region_val[region_counter] = 0;
                //ora dobbiamo controllare dove termina la banda
                for(int k = 0; k < (R+1); k++)
                {
                    // questo ciclo ci serve per trovare la fine della regione,
                    // aggiornando j fin quando line_seq[j] non sara uguale ad 1
                    if(line_seg[j]==1)
                    {
                        //memorizzo la fine della regione, che sarà di vitale importanza per
                        //diseganre le circonferenze sull'immagine originale
                        region_stop[region_counter] = j;
                        //Una volta conclusa una regione bisogna determinare il valore di fold medio
                        mean_region_val[region_counter] /= row_counter;
                        //dopodiche aggiorniamo il contatore delle bande e usciamo dal ciclo
                        region_counter++;
                        break;
                    }
                    //sommo i valori di banda che incontro per poi determinare il valore medio contenuto nel range di bande
                    mean_region_val[region_counter]+=band_value[j];
                    //aggiorno gli indici che indicano le righe controllate
                    j++;
                    row_counter++;
                }
            }
    }
    return region_counter;
}
//===============================================================================
//CHECKSIMMETRY
//Questo metodo permette di determinare il grupopo di simmetria che caratterizza
//la regione in input.
//===============================================================================
void RotationCenter::CheckSimmetry(char gruop[],Mat segFES[],int j,int region_fold[])
{
    //Per determinare le differenti simmetrie riscontrabili
    //abbiamo pensato di effettuare una binarizzazione per contare la densità
    //di pixel bianchi

    Mat thsholdSeg;
    //utilizzando il Thresholding, l'immagine ottenuta conterrà solo pixel bianchi o neri
    threshold( segFES[j], thsholdSeg, 0, 255, CV_THRESH_BINARY);

    //numero di pixel bianchi
    int white=0;
    unsigned char *data = thsholdSeg.data;

    //contiamo i pixel bianchi (255)
    for(int h = 0; h < thsholdSeg.rows; h++)
            for(int w = 0; w < thsholdSeg.cols; w++)
                if(data[h*thsholdSeg.rows+w] == 255)
                            white++;


    //density è la densità num di pixel bianchi/dimensione immagine
    double density = (double)white/(double)(thsholdSeg.cols*thsholdSeg.rows);

    //region_fold indica il valore medio del fold della j-esima banda, se questo è < 2 è più
    //probabile che sia un O(2) in quanto è una componente continua come tutti pixel uniformi o bianchi
    if(region_fold[j] > 2)
    {
        //se il valore è > 2 bisogna determinare se si tratta di una diedrale o ciclica
        //0.1 è un valore empirico
        //che serve per distinguere il tipo di simmetria
        //se vi è molta differenza con 0.1 allora è ciclica altrimenti diedrale
        if(density > 0.1)
            sprintf(gruop," C(%d)",region_fold[j]);
        else
            sprintf(gruop," D(%d)",region_fold[j]);
    }else
    {
        //approssimativamente se il nostro valore di densità è < di DIFF allora è O(2)
        if(density < 0.1)
            sprintf(gruop," O(2)");
        //altrimenti è Diedrale è D(2)
        else
            sprintf(gruop," D(2)");
    }

//questo imshow serve per mostrare a video le bande segmentate come immagini
//imshow(gruop,thsholdSeg);

}

