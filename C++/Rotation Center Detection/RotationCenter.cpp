#include <iostream>
#include "RotationCenter.h"

//===============================================================================
//showFalseColor
//mostra l'immagine con falsi colori
//INPUT:
//- img: immagine in input
//- windows_name: nome della finestra
//
//OUTPUT:
//- falsecolorsmap
//===============================================================================

Mat RotationCenter::showFalseColor(Mat img,string windows_name)
{
    //dato che l'immagine è mappata in un range di valori [0,255]
    //se vogliamo mostrare l'intera gamma di colori (dal nero al bianco)
    //dobbiamo modificare l'immagine in modo tale che copra l'intera gamma
    //per fare cio dichiariamo il minimo e il massimo che serviranno
    //per scalare l'immagine
    double min;
    double max;
    //utilizzo un metodo per ricavare il min e il max dall'immagine
    minMaxIdx(img, &min, &max);

    //calcolo il fattore di scala
    float scale = 255 / (max - min);

    //dichiaro due immagini: adjMap sarà l'immagine in scala di grigio
    //mentre falseColorMap l'immagine finale
    Mat adjMap;
    Mat falseColorsMap;

    //espandiamo il range a 0-255 convertendo l'immagine in scala di grigio
    //void Mat::convertTo(OutputArray m, int rtype, double alpha=1, double beta=0)
    //- il primo parametro è l'immagine di output
    //- il secondso specifica che gli elementi dell'immagine devono essere
    //  degli unsigned char da 0 a 255, altrimenti sarebbero dei char da -128 a +127
    //- il terzo parametro indica un fattore di scala
    //- il quarto parametro è un fattore addizionale alla scala utilizzata
    //  in questo caso convertiamo l'immagine in scala di grigio

    //senza il fattore di scala l'immagine apparirebbe piena
    //di rumore, e senza il parametro scalato l'immagine apparirebbe nera
    img.convertTo(adjMap, CV_8UC1, scale, -min*scale);

    //applico la mappa di colori
    applyColorMap(adjMap,falseColorsMap,cv::COLORMAP_JET);

    //mostro l'immagine ottenuta
    imshow(windows_name, falseColorsMap);
    //lascio l'immagine visibile
    waitKey(1);

    return falseColorsMap;
}

//===============================================================================
//SHOWRSS
//mostra l'immagine in una finestra con falsi colori
//INPUT:
//- img: immagine
//- windows_name: nome della finestra
//- sx: ampiezza immagine
//- sy: altezza immagine
//
//OUTPUT:
//- falsecolorsmap
//===============================================================================

Mat RotationCenter::showRSS(Mat img,string windows_name,int sx,int sy)
{
    //dato che l'immagine è mappata in un range di valori [0,255]
    //se vogliamo mostrare l'intera gamma di colori (dal nero al bianco)
    //dobbiamo modificare l'immagine in modo tale che copra l'intera gamma
    //per fare cio
    //dichiariamo il minimo e il massimo che serviranno per scalare l'immagine
    double min;
    double max;

    //utilizzo un metodo per ricavare il min e il max dall'immagine
    minMaxIdx(img, &min, &max);

     //calcolo il fattore di scala
    float scale = 255 / (max - min);

    //dichiaro due immagini: adjMap sarà l'immagine in scala di grigio
    //mentre falseColorMap l'immagine finale
    Mat adjMap;
    Mat falseColorsMap;

    //espandiamo il range a 0-255
    //void Mat::convertTo(OutputArray m, int rtype, double alpha=1, double beta=0)
    //- il primo parametro è l'immagine di output
    //- il secondso specifica che gli elementi dell'immagine devono essere
    //  degli unsigned char da 0 a 255, altrimenti sarebbero dei char da -128 a +127
    //- il terzo parametro indica un fattore di scala
    //- il quarto parametro è un fattore addizionale alla scala utilizzata
    //  in questo caso convertiamo l immagine in scala di grigio

    //senza il fattore di scala l'immagine apparirebbe piena
    //di rumore, e senza il parametro scalato l'immagine apparirebbe blu scuro
    //converto quindi l'immagine in scala di grigi
    img.convertTo(adjMap, CV_8UC1, scale, -min*scale);

    //Applichiamo un filtro passa Alto
    //nel senso che se un valore dell'immagine convertita [0-255] < soglia
    //allora lo "tagliamo" riducendolo altrimenti lo amplifichiamo
    for(int k=0;k<(adjMap.cols*adjMap.rows);k++)
        {
            if(adjMap.data[k] < 250)
                adjMap.data[k] = adjMap.data[k]/8;
            else
                adjMap.data[k] = adjMap.data[k]*8;
       }

    //applico la mappa di colori
    applyColorMap(adjMap,falseColorsMap,cv::COLORMAP_JET);

    //Applichiamo un resize all immagine ottenuta,
    //per riottenere l'immagine in dimensioni originali
    //in quanto l'RSS nell'elaborazione è stata campionata
    resize(falseColorsMap,falseColorsMap,Size(sx,sy));

    //mostro l'immagine ottenuta
    imshow(windows_name, falseColorsMap);

     //lascio l'immagine visibile
    waitKey(1);

    return falseColorsMap;
}
//===============================================================================
//SHOWSSD
//mostra l'immagine in una finestra con falsi colori
//INPUT:
//- img: immagine
//- windows_name: nome della finestra
//
//OUTPUT:
//- falsecolorsmap
//===============================================================================
Mat RotationCenter::showSSD(Mat img,string windows_name)
{
    double min;
    double max;

    cv::minMaxIdx(img, &min, &max);
    float scale = 255 / (max - min);

    cv::Mat adjMap;
    cv::Mat falseColorsMap;
    img.convertTo(adjMap, CV_8UC1, scale, -min*scale);

    //applichiamo un blur Gaussiano con kernel di dimensione 3x3
    //perchè visivamente rende di più
    GaussianBlur(adjMap,adjMap,Size(3,3),0,0);

    for(int k=0;k<(adjMap.cols*adjMap.rows);k++)
            if(adjMap.data[k] > 255)
                adjMap.data[k] = 255;

    applyColorMap(adjMap,falseColorsMap,cv::COLORMAP_JET);

    imshow(windows_name, falseColorsMap);

    waitKey(1);

    return falseColorsMap;
}

//===============================================================================
//RSS
//Questo metodo viene utilizzato per creare la mappa saliente che ci fornirà una
//prima stima del centro di simmetria rotazionale
//
//INPUT: l'immagine originale
//
//OUTPUT: la mappa RSS
//===============================================================================
Mat RotationCenter::RSS(Mat img)
{
    double thetaStepSize = 1.0;
    // determiniamo il raggio R, come il minimo tra le righe/2 e le colonne/2
    // un raggio dimezzato poiche con un raggio più grande crashava
    int R = min((img.rows-1)/2,(img.cols-1)/2);

    //valore di campionamento
    int sample_val = SAMPLING;

    //Ricavo le dimensioni dell'immagine in input, che ci serviranno
    //come valore di fine del ciclo for
    int rows = img.rows;
    int cols = img.cols;

    //Rideterminiamo i bordi, utilizziamo copymakeborder poiche iniziando la valutazione
    //dal pixel (0,0) e creando una circonferenza di raggio R per evitare crash del software
    //estendiamo l'immagine con valori neri. questo problema coinvolge tutti i valori sui bordi
    //per questo motivo l'estensione avviene su tutti i lati
    copyMakeBorder(img, img, R, R, R, R,BORDER_CONSTANT, Scalar::all(0));

    //Dichiariamo un oggetto Mat che conterrà una copia dell'immagine in input
    //che verrà utilizzata per mostrare a video l'elaborazione in RealTime
    Mat input_image;
    //Copio l'immagine
    img.copyTo(input_image);

    //dichiariamo l'immagine che conterrà la FEP, la DFT e l'RSS
    Mat pImageFE;
    Mat spectral;
    //definiamo un immagine piu piccola rispetto all'originale
    //questo perche è un immagine sottocampionata rispetto all'originale
    //quindi la sua dimensione dipende dal valore del campionamento scelto, il +1
    //è stato messo perche senza crashava
    Mat RSS = Mat::zeros(Size(cols/sample_val+1,rows/sample_val+1),CV_32F);
    //imposto tutti i valori dei pixel dell'RSS inizialmente al valore -10000 per impostare
    //una base "fredda" sulla quale costruire l'RSS map
    RSS = Scalar::all(MIN_VAL);

    // Per ogni pixel dell'immagine campionata calcolo la FEP e applico la DFT,
    // successivamente determino il valore del pixel nell'rss map implementando l'
    // equazione n°3 nel paragrafo 3.2.1, richiamando il metodo rSSik() e passandogli
    // come parametro l'immagine spettrale in output alla DFT. Infine calcolo le coordinate
    // (r,c) del punto nell'RSS map e imposto il valore dell'output nel punto (r,c)
    // i due cicli for seguenti partono da R e terminano sottraendo R perche l'immagine
    // originale è stata estesa inizialmente per questione di bordi e quindi per effettuare
    //l'elaborazione sui soli pixel dell immagine (senza la bordatura estesa nera)
    //abbiamo centrato i for
    for(int i = R; i < (img.rows - R); i += sample_val)
        {
            for(int j = R; j < (img.cols - R); j += sample_val)
            {
                //Effettuo la FEP sul pixel,i parametri in input sono
                // img : immagine in input
                // coordinate del punto (x,y), viene passato j,i
                // poiche la j indica il valore delle x (colonne) e i il valore delle
                // y (le righe)
                // thetaStepSize: è il valore dello step di theta
                // R: raggio utilizzato
                pImageFE = imageFE(img,j,i,thetaStepSize,R);

                //Effettuo la DFT sul risultato della FEP,riga per riga
                // ottenendo un immagine spettrale
                spectral = SpectralImage(pImageFE);

                //Determino il valore dell RSS(x,y) tramite l'equazione
                //descritta nel paper:(3.2.1) equazione n° 3, intensità
                double rss_ji = RSSik(spectral);

                //Ridetermino le coordinate del punto
                // le coordinate essatte del punto nell'RSS map essendo un immagine sottocampionata non coincidono
                // con le coordinate del punto nell'immagine originale (i,j) per questo motivo effettuiamo una trasformazione
                // preliminare, (i-R) per ottenere la giusta posizione in quanto gli indici partono da R con bordi estesi
                //senza effettuare questo ricalcolo l'algoritmo crasha
                int r =(i - R) / sample_val;
                int c =(j - R) / sample_val;

                RSS.ptr<float>(r)[c] = - rss_ji;

                //Puntatore o oggetto strutturante nell'immagine originale che cicla riga per riga
                //prototipo:
                // void circle(Mat& img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
                circle(input_image, Point(j, i), 2, Scalar(255, 0, 0));
                imshow("image original", input_image);

            }
        }
    return RSS;
}



//===============================================================================
//IMAGEFE
//Il metodo "imageFE" presa un immagine Mat in input
//come parametro, ci permette di effettuare una trasformazione
//da spazio cartesiano a spazio polare, centrando una circonferenza in
//un punto dell'immagine dato in input, di raggio pari al minimo tra
//la larghezza e l'altezza (questo per non sforare al di fuori
//dell'immagine). Spostandoci in senso orario da PI a 0, simuliamo
//due raggi (il diametro) e  li facciamo ruotare estrapolando ogni pixel
//dal diametro e inserendolo in una nuova immagine come nuova Colonna.
//In altre parole, ogni diametro del cerchio sarà la colonna dell'immagine
//risultato. Effettuando cosi la trasformazione.
//
//INPUT:
//  - img: immagine in input
//  - xc: coordinata x del centro potenziale
//  - yc: coordinata y del centro potenziale
//  - step : step
//  - R: raggio di ricerca
//
//output:
//  - immagine FE
//===============================================================================

Mat RotationCenter::imageFE(Mat img,int xc, int yc, double step,int R)
{

    //Impostiamo la larghezza dell'immagine Polare risultante a 360 (teta)
    int PolarImgWidth = 360;
    //impostiamo l'altezza dell'immagine Polare come doppio del raggio
    int PolarImgHeight = 2 * R;
    //Determiniamo il size dell'immagine Polare, come prodotto dell'altezza
    //per la larghezza, mi servirà per determinare la dimensione del vettore
    //che conterrà i pixel della nuova immagine.

    int PolarImgSize = PolarImgWidth * PolarImgHeight;
    //Estrapoliamo i pixel dall'immagine originale
    //i quali poi verranno utilizzati per creare le colonne della FE
    unsigned char *data_img = img.data;

    //creiamo un area di memoria che conterrà i dati dell'immagine
    //finale
    unsigned char *data_fe = new unsigned char[PolarImgSize];

    //Iniziamo con la Conversione Da Spazio Cartesiano a Spazio Polare
    //Creiamo due cicli for: il primo ciclerà da 0 a 360 rappresentando
    //gli angoli (teta) in gradi, il secondo sarà l'indice del pixel
    //che scorrerà lungo tutto il diametro (2*R) dove R è il raggio.
    //Per fare ciò inizialmente abbiamo due possibilità o ci troviamo
    //all'estrema sinistra dell'immagine (Pi greco) e quindi dobbiamo
    //spostarci verso il centro, oppure ci troviamo dopo il centro
    //e dobbiamo spostarci verso la destra dell'immagine.
    //Questa informazione la ricaviamo dal valore di r rispetto a R.
    //Se r > R significa che essendo partiti da sinistra abbiamo
    //appena superato il valore del raggio, quindi il centro, e allora
    //dobbiamo spostarci verso la DESTRA dell'immagine, altrimenti
    //siamo all'estremo SINISTRO dell'immagine (valore del raggio
    // partendo dal centro) e dobbiamo spostarci verso il centro.
    //Infine inseriamo nel vettore dell'immagine risultante ogni pixel
    //cosi determinato colonna per colonna.

    for ( int angle = 0; angle < 360; angle+=step )
    {
        for ( int r = 0; r < 2*R; r++ )
        {
            //dichiariamo teta come double che ci indicherà i valori degli
            //angoli (angle) espressi in radianti
            double teta = 0.0;
            //x e y saranno le coordinate dei pixel
            int x = 0;
            int y = 0;

            //Controlliamo la nostra posizione rispetto al raggio
            if(r > R)
            {
                //Dal CENTRO verso DESTRA

                //Caso in cui r (il nostro indice è maggiore del Raggio R
                //Questo significa che con l'indice r abbiamo superato la
                //dimensione del raggio
                //Quindi camminiamo tendendo all'estrema destra.

                //converto gli angoli in radianti e li memorizzo in teta
                teta = M_PI * angle / 180;

                //effettuo i calcoli per estrapolare i giusti pixel
                //lo casto ad int poichè dopo mi serviranno per impostare
                //le posizioni giuste nell'immagine
                x = (int) round(xc + (r - R) * cos(teta));
                y = (int) round(yc + (r - R) * sin(teta));
            }
            else
            {
                //Da SINISTRA verso il CENTRO

                //Caso in cui r (il nostro indice è minore di R)
                //Questo significa che siamo alle prime iterazioni quindi ci spostiamo
                //da sinistra verso il centro.

                //Dovendoci spostare da sinistra verso il centro
                //Sommiamo all'angolo che inizialmente sarà 0, 180 che ci permette di
                //andare a PI.
                //trasformo teta in radianti
                teta =  M_PI * (angle + 180) / 180;

                //effettuo i calcoli per estrapolare i giusti pixel
                x = (int) round(xc + (R - r) * cos(teta));
                y = (int) round(yc + (R - r) * sin(teta));
            }

            //Inserisco uno alla volta i pixel estratti dall'immagine originale e li
            //inserisco nel vettore che poi trasformerò in immagine
            // il puntatore sul raggio (r) sarà la mia y e l'angolo la mia x,
            //l'inserimento avviene dall'alto verso il basso seguendo le colonne
            data_fe[PolarImgWidth*r + (int)angle] = data_img[img.cols*y + x];
         }
     }

    //Dichiaro l'immagine finale, che avrà le dimensioni definite
    //in precedenza. Il prototipo della Mat prevede il size e una costante
    //che indichi i valori contenuti nell'immagine in questo caso 8UC1
    //CV_8UC1 è una costante che sta ad indicare che i valori dell'immagine
    //dovranno essere Unsigned Char ad 8 bit
    //Mat::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP)
	Mat img_fe = Mat(PolarImgHeight, PolarImgWidth, CV_8UC1);

	//Una volta creata l'immagine delle giuste dimensioni dobbiamo copiarci
	//tutti i dati elaborati che sono contenuti in "data_fe", utilizziamo il
	//metodo memcpy():
	//void * memcpy ( void * destination, const void * source, size_t size );
	//quindi copio in img_fe (immagine di output) quello che trovo in data_fe
	//per una dimensione indicata da PolarImgSize
	memcpy(img_fe.data, data_fe, PolarImgSize);

    //mostro l'immagine cosi ottenuta
    imshow("image FE", img_fe);

    //dealloco la memoria allocata precedentemente
    delete []data_fe;
    //ritorno l'immagine risultante (FE)
    return  img_fe;
}

//===============================================================================
//SPECTRALIMAGE
//Questo metodo viene richiamato da RSS dopo aver effettuato la FE.
//Ottenuta l'immagine FE dobbiamo applicare la dft riga per riga, implementare
//la formula descritta nel paper (rif: 3.2.1 eq 2) per calcolare l'energia spettrale
//che ci permetterà di stimare il centro di rotazione
//INPUT:  - immagine FE
//OUTPUT: - immagine "spettrale"
//===============================================================================

Mat RotationCenter::SpectralImage(Mat img)
{
    int M = getOptimalDFTSize( img.rows );
    int N = getOptimalDFTSize( img.cols );

    Mat padded;
    copyMakeBorder(img, padded, 0, M-img.rows, 0, N-img.cols,BORDER_CONSTANT, Scalar::all(0));

    Mat padded_float = Mat_<float>(padded);

    Mat dft_img = Mat::zeros(padded_float.size(),CV_32F);
    Mat spectral = Mat::zeros(padded_float.size(),CV_32F);

    //Effettuo la DFT su ogni riga dell'immagine
    for (int k = 0; k < padded_float.rows; k++)
        {
            Mat *planes = rowDft(padded_float.row(k));
            rowSpectral(planes).copyTo(spectral.row(k));
            delete []planes;
        }
    showFalseColor(spectral,"Spectral DFT");
    return spectral;
}

//===============================================================================
//ROWDFT
//Effettuo la DFT su ogni riga della FE, utilizzando il metodo dft implementato
//in opencv
//
//INPUT:
//FErow: riga della FE
//
//OUTPUT:
//planes: contiene la parte reale e quella immaginaria della DFT
//===============================================================================

Mat *RotationCenter::rowDft(Mat FErow)
{
    //Qui prendiamo in input la k-esima riga dell'immagine paddata
    //che non contiene ancora nulla e diamo in output una riga di
    //coefficienti risultanti dall'operazione di DFT.

    // Il risultato della DFT è complesso. Ciò implica che per ogni valore dell'
    // immagine risultante avremo due valori immagine (uno per componente).
    // Inoltre, la gamma del dominio della frequenza è molto più grande rispetto
    // alla sua controparte spaziale. Pertanto, è utile memorizzare questi valori
    // in un formato float e per farlo convertiremo la nostra riga in ingresso a
    // float e la espandiamo con un altro canale per contenere i valori complessi
    Mat complexImg;

    //Dichiaro un immagine planes che conterrà i valori della DFT
    //conterrà sia i valori reali che immaginari discriminati dal valore di planes(0,1)
    Mat *planes = new Mat[2];
    //inizializzo planes[0] e planes[1] come righe, che conterranno i coefficienti
    //calcolati dalla DFT
    planes[0] = Mat_<float>(FErow);
    planes[1] = Mat::zeros(FErow.size(),CV_32F);

    // il metodo merge() fonde più array per creare un singolo array multicanale
    //poiche il metodo DFT non accetta singoli planes ma un immagine "completa"
    // void merge(const Mat* mv, size_t count, OutputArray dst)
    merge(planes, 2, complexImg);

    // calcolo la dft sull'immagine che deve contenere i valori complessi
    dft(complexImg, complexImg);

    //Una volta calcolata la dft sull'immagine "completa", bisogna
    //ridividerla in planes in modo tale da poter lavorare sulle singole
    //componenti. per fare ciò utilizziamo il metodo split()

    // divido l'immagine complessa in "planes" per accedere alle componenti
    // planes[0] conterrà la parte reale, planes[1] la parte immaginaria
    // split() è il metodo inverso a merge()
    split(complexImg, planes);

    return planes;
}

//===============================================================================
//rowSpectral
// Calcola l'energia spettrale , implementando l'equazione presente nel paper
// Eq (2) (cap 3.2.1)
//
// INPUT:
// *planes: risultato di rowDFT, contiene i coefficienti DFT con parte reale
// e parte immaginaria
//
// OUTPUT:
// spectral: energia spettrale di tutte le righe ,risultato dell'equazione
//===============================================================================

Mat RotationCenter::rowSpectral(Mat *planes)
{
    //Dichiaro l'immagine di output che sarà una riga
    // inizializzandola a tutti 0 con il size determinato dal numero d coefficienti
    //di planes[0] (riga contenente i coefficienti reali)
    //32F è la costante che indica la gamma di valori che potranno
    //assumere i pixel in questo caso 32bit float
     Mat spectral = Mat::zeros(planes[0].size(),CV_32F);

    // calcolo l'energia spettrale (S(k,j)) seguendo la formula data dall'articolo
    //riferimento: cap 3.2.1
     for (int j = 0; j < planes[0].cols; j++)
        {
            // estraggo la parte immaginaria del coefficiente j-esimo
            double imag = planes[1].ptr<float>(0)[j];
            // estraggo la parte reale del coefficiente j-esimo
            double real = planes[0].ptr<float>(0)[j];
            // calcolo per ogni pixel dell'immagine che conterrà l'energia spettrale
            // la formula data dall'articolo: Re(DFT(img))**2 + Im(DFT(img))**2
            spectral.ptr<float>(0)[j] = (float)((real*real) + (imag*imag)); //Eq (2) (cap 3.2.1)
        }
     return spectral;
}

//===============================================================================
//RSSik
//In questo metodo bisogna implementare l'equazione descritta in: pag1663 eq n°3
//
//INPUT:
//dftImage: prendiamo in input l'immagine dft e lavoriamo su una porzione di essa
//
//OUTPUT:
//result: è un valore double, poiche rappresenta il risultato dell'equazione
//che verrà poi utilizzato per costruire l'RSS map
//===============================================================================

double RotationCenter::RSSik(Mat dftImage)
{
    //Dichiaro le variabili che verranno utilizzate
    //la variabile che conterrà la media
    double mean=0.0;

    //la variabile che conterrà la deviazione standard
    double stddev=0.0;

    //media picchi
    double mean_peak=0.0;

    //la variabile che conterrà il risultato dell'equazione
    double result=0.0;

    //dichiaro una sottoimmagine della DFT in input,poiche
    // come da articolo bisogna lavorare su una porzione
    // definita dalle stesse righe ma da metà colonne tranne la prima
    //riferimento: 3.2.1
    Mat subDFT = dftImage.colRange(1,dftImage.cols / 2).rowRange(0,dftImage.rows);

    //ciclo su tutte le righe della porzione
    for(int i = 0; i < subDFT.rows; i++)
        {
            //ad ogni ciclo riazzero le variabili
            mean=0.0;
            stddev=0.0;
            mean_peak=0.0;

            //array dei coefficienti, ci serve per salvare tutti i picchi trovati
            //per poi calcolare il valore di "pr"
            int peaks_index[subDFT.rows];

            //calcolo la media dei valori di ogni riga
            //in questo ciclo li sommo tutti e li memorizzo in mean
            for (int k = 1; k < subDFT.cols; k++)
                mean += (double)dftImage.ptr<float>(i)[k];

            //qui effettuo la divisione per il numero di colonne
            //ed ottengo la media
            mean /= subDFT.cols;

            //calcolo la deviazione standard di ogni riga
            //FORMULA:
            //sqrt[(valore - media)^2 / dimensione]
            for (int k = 1; k < subDFT.cols; k++)
                {
                    double x = ((double)dftImage.ptr<float>(i)[k] - mean);
                    stddev += x * x;
                }

            stddev = sqrt(stddev / subDFT.cols);

            //dichiaro un contatore, che mi servirà
            //per definire la posizione corretta
            //nell'array sd_coefficienti
            int peak_counter=0;

            //Cerco i picchi, e per farlo devo
            //controllare che la condizione Sik(r,kpeak)> (mean + 2 * stddev)
            //sia soddisfatta, se si allora sono in presenza di un picco
            //e salvo il suo indice nell'array dei coefficienti aggiornando il contatore
            for (int k = 1; k < subDFT.cols; k++)
                {
                    //controllo la condizione su ogni coefficiente della riga
                    if(dftImage.ptr<float>(i)[k] > (mean + 2 * stddev))
                    {
                        //ho trovato un picco, ora bisogna calcolare la media
                        //dei picchi
                        mean_peak += dftImage.ptr<float>(i)[k];
                        //salvo l'indice della colonna del picco trovato
                        //nell'array dei picchi che ci servirà per calcolare
                        //rho
                        peaks_index[peak_counter] = k;
                        //aggiorno il numero di picchi trovati
                        peak_counter++;
                    }
                }

            //devo calcolare ro, per fare ciò il paper
            //ci dice che bisogna verificare che gli indici di tutti i picchi
            //siano multipli del primo, in caso affermativo ro = 1 altrimenti 0
            //appena si incontra uno che non è multiplo

            // definisco ro = 1
            double pr=1.0;

            //se ho trovato almeno un picco
            if(peak_counter != 0)
                {
                   for(int k = 0; k < peak_counter; k++)
                    {
                        //controllo che il k-esimo indice sia multiplo del primo (quello
                        //piu piccolo) in caso affermativo ro resta 1 altromenti lo
                        //impostiamo a 0
                        if(peaks_index[k] % peaks_index[0] != 0)
                        {
                                pr = 0.0;
                                break;
                        }
                    }
               }

            //calcoliamo il risultato dividendo la media dei picchi
            //con la media dei coefficienti
            //moltiplicandolo per ro e salvandolo in result
            //formula:
            //mean(Sxy(r,kpeak))/mean(Sxy(r,k)) in sommatoria

            //preveniamo una divisione per 0
            if(mean != 0 && peak_counter!=0)
                {
                        //calcolo la media dei picchi dividendola
                        //per il numero di picchi trovati
                        mean_peak /= peak_counter;
                        //ottengo il risultato finale
                        result += pr * (mean_peak/mean);

                }
    }

    return result;
}

//===============================================================================
//SSD
//Questo metodo calcola la mappa SSD, e il potenziale centro di simmetria rotazionale.
//
//INPUT:
//- img: l'immagine originale
//OUTPUT:
//- xi: cordinata x del potenziale centro stimato
//- yi: coordinata y del potenziale centro stimato
//- Dxy:l'immagine contenente l'SSD
//===============================================================================

Mat RotationCenter::SSD(Mat img,int &xc, int &yc)
{
    //Dichiariamo l'immagine Dxy che conterrà l'SSD,
    //original_img che conterrà l'immagine originale sulla quale
    //di volta in volta verranno disegnati i BF
    //falseColorSsd che mostrerà l'SSD in falsi colori
    Mat Dxy;
    Mat original_img;
    Mat falseColorsSsd;

    //Dichiariamo due variabili double che indicheranno
    //rispettivamente la fase del punto i e del punto j
    double pi,pj;

    //Dichiariamo due array che conterranno l'output del
    //metodo BidirectionalFlow , ovvero le 4 coordinate
    //dei due punti di ogni linea (BF)
    //- ckVal_i conterrà (x0,yo) e (x1,y1) che saranno
    //memorizzati nell'array Ck in BidirectionalFlow in posizione
    //0,1 e 1,2
    int *ckVal_i;
    //vale la stessa cosa per ckVal_j
    int *ckVal_j;

    //SSD espressa come mappa di accumulazione
    //di dimensione pari al size dell'immagine originale
    unsigned char *accumulator_image = new unsigned char[img.rows*img.cols];
    //pulisco la memoria
    memset(accumulator_image,0L,img.rows*img.cols);

    //scorro l'intera immagine pixel per pixel
    for(int yi=0;yi<img.rows;yi+=SAMPLING)
        {
        for(int xi=0;xi<img.cols;xi+=SAMPLING)
        {

            //Questo è un passo fondamentale per la
            //veduta a video, la logica è disegnare due bidirectionalflow
            //incrociarli e dopodiche riaggiornare l'immagine
            //senza questa istruzione l'immagine a video non viene aggiornata
            //e di conseguenza tutti i bidirectionalflow calcolati restano come linee
            //a video che ricoprono l'immagine
             img.copyTo(original_img);

            //Determiniamo il primo BF, passando
            //l'immagine originale, le coordinate del
            //primo pixel, la phase (output) e il raggio
            ckVal_i = bidirectionalFlow(img,xi,yi,pi);

            //a questo punto abbiamo le coordinate del
            //primo BF e creiamo i punti (inizio e fine)
            //tramite il metodo Point()

            Point Ci = Point(ckVal_i[0],ckVal_i[1]);
            Point Ck = Point(ckVal_i[2],ckVal_i[3]);

            //disegnamo la linea che collega i due punti
            //Ci e Ck rispettivamente inizio e fine del
            //primo BidirectionalFlow
            //Prototipo:
            //void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1,
                        // int lineType = 8, int shift=0)

            line(original_img,Ci,Ck,Scalar(255,0,0),2,8);

            //A questo punto bisogna determinare il secondo
            //Bidirectional flow, in modo tale che venga scelto
            //in un range di valori intorno al centro stimato dall'RSS
            //calcoliamo due coordinate casuali
            //per la x e la y nell'intorno +-32 dal centro
            //stimato dall'RSS
            int xj=(rand()% ((xc+32) - (xc - 32)))+ (xc - 32);
            int yj=(rand()% ((yc+32) - (yc - 32)))+ (yc - 32);

            //Calcoliamo le coordinate del BF passandogli
            //i punti casuali scelti predentemente
            ckVal_j = bidirectionalFlow(img,xj,yj,pj);

            //determiniamo i punti tramite il metodo Point
            Ci=Point(ckVal_j[0],ckVal_j[1]);
            Ck=Point(ckVal_j[2],ckVal_j[3]);

            //Disegnamo la linea che collega le due estremità
            line(original_img,Ci,Ck,Scalar(128,0,0),2,8);

            //A questo punto bisogna Intersecare i due Bidirectional flow
            //per fare ciò calcoliamo il punto di intersezione C come descritto
            // nel paper riferimento: 3.2.2 eq 6.

            //Determiniamo lo Slope dei due punti come da paper
            //riferimento: 3.2.2 eq 6.
            double si = (-1/tan(pi));
            double sj = (-1/tan(pj));

            //Il punto di intersezione dei due BF, C,
            //avrà coordinate determinate dall equazione di riferimento
            int iCX = (si*xi-sj*xj+yj-yi)/(si-sj);
            int iCY = (si*sj*(xi-xj)+si*yj-sj*yi)/(si-sj);

            //Evidenziamo il punto C tramite il metodo
            //Circle che disegna un cerchietto nel punto di coordinate
            //iCY e iCY
            circle(original_img,Point(iCX,iCY),6,Scalar(255,0,0),2);

            //Controlliamo se le coordinate del punto di intersezione
            //sono comprese all'interno dell immagine
            if(iCX>0 && iCX<img.cols && iCY>0 && iCY<img.rows)
                    //accomulator_image sarà l'immagine SSD
                    //formata come punti di accomulazione di tutti
                    //i bidirectionalFlow calcolati.
                    //l'accumulazione avviene sommando 1 ad ogni
                    //intersezione
                    accumulator_image[((iCY*img.cols)+iCX)] += 1;

            //A questo punto possiamo mostrare a video i
            //BidirectionalFlow calcolati

            imshow("Bidirectional Flow",original_img);

            //prototipo Mat:
            //Mat::Mat(Size size, int type, void* data, size_t step=AUTO_STEP)
            Dxy = Mat(Size(img.cols,img.rows),CV_8UC1,accumulator_image, Mat::AUTO_STEP);

            //mostro l'SSD mentre viene elaborata
            falseColorsSsd=showSSD(Dxy,"SSD");

            //dealloco lo spazio allocato precedentemente
            delete []ckVal_i;
            delete []ckVal_j;

            waitKey(1);
        }
    }

    return Dxy;
}




//===============================================================================
//BIDIRECTIONALFLOW
//Questo metodo viene utilizzato per determinare i BidirectionalFlow, prendendo due punti
//casuali
//INPUT:
//- img: l'immagine originale
//- xi: cordinata x del punto iniziale
//- yi: coordinata y del punto iniziale
//- &phase : è un argomento di OUTPUT che indica la "fase" calcolata
//OUTPUT:
//- CK: vettore contenente 4 coordinate, rispettivamente del punto inizla e finale
//      del BidirectionalFlow
//===============================================================================

int *RotationCenter::bidirectionalFlow(Mat img,int xi,int yi,double &phase)
{
    //vettore di interi che conterrà le coordinate dei due punti
    //che delimitano i BidirectionalFlow
    //è scelto di interi poiche l'immagine viene scandita con indici e passo interi
    int *Ck = new int [4];

    //definisco lo step e il raggio
    double thetaStepSize = 1.0; //2*M_PI/90
    //determino il raggio
    int R=min((img.rows-1)/2,(img.cols-1)/2);
    //estendo i bordi dell'immagine , quindi creo un immagine paddata
    copyMakeBorder(img, img, R, R, R, R,BORDER_CONSTANT, Scalar::all(0));

    //Calcolo la FE
    Mat pImageFE = imageFE(img,xi+R,yi+R,thetaStepSize,R);

    //A questo punto bisogna calcolare la fase implementando la formula:
    //phase(r) = arctan(Re(r,2)/Im(r,2)), per ogni riga r
    double *phase_r = imageRowsDft(pImageFE);
    //la fase è determinata come il valore mediano tra i valori calcolati
    phase = medianValue(phase_r,pImageFE.rows);

    // a questo punto bisogna determinare le due estremità del
    //Bidirectional flow, per comodità cerco di prendere punti dall'alto (y=0)
    //verso il basso (y = img.rows) , mentre le x le determino grazie ad una variante
    //della formula descritta sul paper.

    //Seguendo l'equazione del paper viene determinato un solo punto, impedendo
    //di vedere i bidirectionalflow

    //1 PUNTO
    //y=0 poiche presumo che il primo punto parta dall'alto
    //la x viene calcolata adattando la formula del paper
    //che permetteva di far passare il bidirectionalflow attraverso
    //il punto c d coordinate xi,yi

    int yk=0;
    int xk=xi+yi*tan(phase)-tan(phase)*yk;

    //Utilizzando equazione del paper
    //int yk=tan(phase)/(xi+yi*tan(phase));
    //int xk=1/(xi+yi*tan(phase));

    //memorizziamo nelle posizioni 0 e 1 dell'array Ck
    //le coordinate del punto iniziale del BF

    Ck[0]=xk;
    Ck[1]=yk;

    //2 PUNTO
    //y=img.rows poiche il secondo punto parte dalla posizione
    //opposta all'altro cioè dal basso
    //la x è calcolata sempre con la variante dell'equazione

    yk=img.rows;
    xk=xi+yi*tan(phase)-tan(phase)*yk;

    //utilizzando l'equazione del paper
    //yk=tan(phase)/(xi+yi*tan(phase));
    //xk=1/(xi+yi*tan(phase));

    //memorizziamo nelle posizioni 2 e 3 dell'array Ck
    //le coordinate del secondo punto del BF

    Ck[2]=xk;
    Ck[3]=yk;

    return (int *)Ck;
}

//===============================================================================
//IMAGEROWDFT
//===============================================================================
double *RotationCenter::imageRowsDft(Mat img)
{
    //Per prima cosa otteniamo il size ottimale per applicare successivamente la DFT
    int M = getOptimalDFTSize( img.rows );
    int N = getOptimalDFTSize( img.cols );

    //ovviamente, sistemando le dimensioni l'immagine risultante avrà dimensioni
    //maggiori. Dichiariamo quindi l'immagine padded (che sarà l'immagine dft estesa)
    Mat padded;

    //Estendo i bordi dell'immagine originale salvandola in padded
    copyMakeBorder(img, padded, 0, M-img.rows, 0, N-img.cols,BORDER_CONSTANT, Scalar::all(0));

    //casto i valori dell'immagine a float
    Mat padded_float = Mat_<float>(padded);

    //A questo punto dichiariamo due immagini che conterranno
    //rispettivamente i valori reali e immaginari che
    //serviranno per implementare l'equazione per calcolare la fase
    //di ogni riga.
    Mat dft_real = Mat::zeros(padded_float.size(),CV_32F);
    Mat dft_imag = Mat::zeros(padded_float.size(),CV_32F);
    //Dichiariamo un array dinamico che conterrà tanti valori quanti sono
    //le righe dell'immagine in inpput
    double *phase = new double[padded_float.rows];

    //Ciclo su tutte le righe dell'immagine
    for (int k = 0; k < padded_float.rows; k++)
        {
            //per ogni k-esima riga calcolo la DFT su ogni riga della FEP (immagine in input paddata)
            //ottenendo in output planes che conterrà i coefficienti della DFT (reali-immag)
            Mat *planes = rowDft(padded_float.row(k));

            //salvo i coefficienti reali
            planes[0].row(0).copyTo(dft_real.row(k));
            //salvo i coefficienti immaginari
            planes[1].row(0).copyTo(dft_imag.row(k));

            //calcolo la formula per la fase della k-esima riga:
            //phase rows[k] = arcotan(real(2)/imag(2))
            //riferimento: 3.2.2 eq 4
            //bisogna calcolare l'arcotangente (atan) utilizzando il
            //secondo componente della DFT della k-esima riga
            phase[k]=atan((dft_real.ptr<float>(k)[1])/(dft_imag.ptr<float>(k)[1]));

            //cout<<phase[k]<<"\n";

            delete []planes;
    }

    return phase;
}

//===============================================================================
//GETCENTER
//Determino la stima del centro potenziale che sarà caratterizzato dal valore
//di picco massimo, quindi ricerchiamo il massimo locale all'immagine
//ritornando anche l'immagine in scala di grigio (rss map)
//===============================================================================

Mat RotationCenter::getCenter(Mat RSSimg,Point &maxloc)
{
    double maxVal;
    double minVal;
    Point minloc;
    //convertiamo l'immagine in scala di grigio
    cvtColor(RSSimg, RSSimg, CV_RGB2GRAY);
    //utilizziamo il metodo minMaxLoc pper determinare il massimo locale
    //dove presumibilmente verrà stimato il centro di simmetria rotazionale
    minMaxLoc(RSSimg, &minVal, &maxVal,&minloc,&maxloc);
    //restituiamo l'immagine in scala di grigio, il valore del massimo
    //sarà contenuto in maxLoc
    return RSSimg;
}

//===============================================================================
//MEDIANVALUE
//===============================================================================
double RotationCenter::medianValue(double *val,int size)
{
    //ordino l'array dei valori preso in input
    sort(&val[0], &val[size]);
    //se il size è pari ritorno il valore centrale
    if ((size % 2)==0)
        return val[size/2];
    else
        //altrimenti il valore ottenuto dalla formula
        // val centrale -1 + val centrale fratto 2
        return (val[size / 2 - 1] + val[size / 2]) / 2;
}
