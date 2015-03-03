//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Progetto di Elaborazione delle immagini
//di
//Studente: Josef Vitanostra
//Matricola: 0124/224
//
//Studente: Selvaggio Michele
//Matricola: 0124/940
//
//Progetto tipologia A basato sull'Articolo:
//----------------------------------------------------------------------------------------------------
//"Skewed Rotation Symmetry Group Detection"
//IEEE TRANSACTIONS ON PATTERN ANALYSIS AND MACHINE INTELLIGENCE,   VOL. 32,   NO. 9,   SEPTEMBER 2010
//Seungkyu Lee, Student Member, IEEE, and Yanxi Liu, Senior Member, IEEE
//----------------------------------------------------------------------------------------------------
//
//Main.cpp
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include "RotationCenter.h"
//===============================================================================
//READIMAGE
//La funzione readImage prende come parametro il path di
//un immagine e ci permette di caricare un immagine
//tramite "imread" in scala di grigio e mostrarla a video.
//L'immagine viene caricata in scala di grigio per permettere
//una più facile elaborazione della DFT successivamente passando
//da 32bit a 3 canali(RGB) ad 8bit a 2 canali.
//===============================================================================

Mat readImage(string path)
{
    //Dichiariamo un oggetto Mat e mediante imread carichiamo
    //l'immagine indicata dal path in scala in grigio

    Mat img = imread(path,CV_LOAD_IMAGE_GRAYSCALE);
    //Controlliamo che l'immagine esista davvero, in caso
    //contrario terminiamo

    if (img.empty())
        {
            cout<<"Immagine non trovata\n";
            exit(-1);
       }

    //Ritorniamo il riferimento all'immagine appena caricata
    return img;
}
//===============================================================================
//IMAGECHOOSER
//La funzione ImageChooser permette di scorrere una directory e scegliere un immagine
//da elaborare, restituisce quindi in output il nome dell'immagine.
//===============================================================================
string ImageChooser()
{

    //dichiariamo un oggetto DIR* directory che ci servirà per aprire la directory
    //dove sono contenute le immagini
    DIR		*directory;
    string image;

    // apriamo la directory
    directory = opendir("test_in");

    //Permettiamo all'utente di scegliere un immagine da elaborare
    cout << "\nScegli l'immagine da elaborare:\n";

    // se non vi sono errori durante l'apertura
    if (directory)
        {
            //dichiariamo un oggetto della classe dirent che mi servirà
            //come puntatore ai file incontrati
            dirent	*file;

            // scorriamo la directory aperta precedentemente
            while ((file = readdir(directory)) != NULL)
                {
                   // estrapoliamo solo il nome dei file di tipo immagine che incontriamo
                   //(.jpg oppure .png) e lo mostriamo a video
                    if (strstr(file->d_name, ".jpg") || strstr(file->d_name, ".png"))
                            cout << file->d_name << endl;
                }
          }

    // preleviamo la scelta dell'utente
    cout<<"\nInserisci il nome dell'immagine scelta -> ";
    cin>>image;

    //Ritorniamo il nome dell'immagine scelta
    return image;
}

//===============================================================================
//Main
//===============================================================================

int main(int argc,char **argv)
{
    cout<<"\t**************************************************************"<<endl;
    cout<<"\t********** Progetto di Elaborazione delle Immagini: **********"<<endl;
    cout<<"\t********** Skewed Rotation Simmetry Group Detection **********"<<endl;
    cout<<"\t**************************************************************"<<endl;
    cout<<"Premere un tasto per iniziare l'elaborazione"<<endl;

//--------------------------------------------------------------------------------//

    //----------------------------------------
    //  Scelta dell'immagine da elaborare     |
    //----------------------------------------

	//facciamo scegliere l'immagine da elaborare
	//ottenendone il nome
    string img_in = ImageChooser();

    //determiniamo il path dove creare la directory
    string dir_path = "test_out/"+img_in;
    //creiamo la directory
    if(mkdir(dir_path.c_str()))
        cout << "Directory creata con successo" << endl;

    int len = sizeof(img_in);
    string name_img =img_in.substr(0,len-2);

	//creiamo i nomi delle immagini di output
    string rss_out=(dir_path+"/"+name_img+"_RSS_Out.jpg");
    string ssd_out=(dir_path+"/"+name_img+"_SSD_Out.jpg");
    string seg_out=(dir_path+"/"+name_img+"_Out_Seg.jpg");
    string gray_rss_name=(dir_path+"/"+name_img+"_RSS_Gray_Out.jpg");
    string gray_ssd_name=(dir_path+"/"+name_img+"SSD_Gray_Out.jpg");

	//leggo l'immagine scelta
    Mat original_img = readImage("test_in/"+img_in);

    //Riduzione del Rumore
    blur(original_img, original_img,Size(2,2));

//--------------------------------------------------------------------------------//

    //----------------------------------------
    //  Calcolo della mappa di salienza RSS   |
    //----------------------------------------

    cout<<endl<<"*****************************************************"<<endl<<endl;
    cout<<"Calcolo della mappa di salienza RSS"<<endl;

	//inizio dell'elaborazione
    RotationCenter cd;
    Mat rss = cd.RSS(original_img);

	//otteniamo l'RSS map in falsi colori
    Mat false_color = cd.showRSS(rss,"RSS",original_img.cols,original_img.rows);
    //salviamo l'immagine sul disco
    if(imwrite(rss_out,false_color))
         cout<<rss_out+" salvata con successo!"<<endl;

    //Ottenniamo il centro
    Point cpt;
    //richiamiamo il metodo per trovare il massimo locale
    //il quale ci restituirà anche l'immagine in scala di grigi
    Mat gray_rss = cd.getCenter(false_color,cpt);

    //evidenziamo il centro cosi stimato con un cerchietto
    circle(gray_rss, cpt, 3, Scalar(0, 0, 0), 2);
    //mostriamo l'RSS in scala di grigi
    imshow("Gray RSS",gray_rss);

    //salviamo l'immagine
    if(imwrite(gray_rss_name,gray_rss))
       cout<<"RSS in scala di grigio salvata con successo!"<<endl;

    //mostriamo le coordinate del centro stimato
    cout<<"RSS: Stima del Centro di Rotazione: ("<<cpt.x<<","<<cpt.y<<")"<<endl;

//--------------------------------------------------------------------------------//

    //----------------------------------------
    //  Calcolo della mappa di salienza SSD   |
    //----------------------------------------

    cout<<endl<<"***************************************************************************"<<endl<<endl;
    cout<<"Calcolo della mappa di salienza SSD"<<endl;

    //SSD
    Mat ssd = cd.SSD(original_img,cpt.x,cpt.y);
    //Mostriamo l'SSD in falsi colori una volta terminata l'elaborazione
    ssd = cd.showSSD(ssd,"SSD");
    if(imwrite(ssd_out,ssd))
         cout<<ssd_out+" salvata con successo!"<<endl;

    //Stima del centro di simmetria
    //richiamiamo il metodo per trovare il massimo locale
    //che ci restituirà anche l'SSD in scala di grigi
    ssd = cd.getCenter(ssd,cpt);
    //evidenziamo il centro di simmetria rotazionale cosi stimato
    circle(ssd, cpt, 3, Scalar(0, 0, 0), 2);
    //mostriamo l'SSD in scala di grigi
    imshow("Gray SSD",ssd);
    //salviamo l'immagine sul disco
    if(imwrite(gray_ssd_name,ssd))
         cout<<"SSD in scala di grigio salvata con successo!"<<endl;

    //Mostriamo le coordinate del centro stimato
     cout<<"SSD: Stima del Centro di Rotazione: ("<<cpt.x<<","<<cpt.y<<")"<<endl<<endl;

//--------------------------------------------------------------------------------//

    //--------------------------------------------
    //  Segmentazione della FE e check simmetry   |
    //--------------------------------------------

     cout<<"***************************************************************************"<<endl<<endl;
     cout<<"Segmentazione della FE e determinazione dei gruppi di simmetria rotazionale "<<endl;

    Mat segmented = cd.feSeg(original_img,cpt.x,cpt.y);
    if (imwrite(seg_out,segmented))
        cout<<seg_out+" salvata con successo!"<<endl;

    waitKey(0);
}
