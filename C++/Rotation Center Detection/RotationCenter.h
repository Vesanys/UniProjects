//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Progetto di Elaborazione delle immagini
//candidati
//Studente: Josef Vitanostra
//Matricola: 0124/224
//
//Studente: Selvaggio Michele
//Matricola: 0124/940
//
//Progetto tipologia A basato sull'Articolo:
//--------------------------------------------------------------
// "Skewed Rotation Symmetry Group Detection"
// IEEE TRANSACTIONS ON PATTERN ANALYSIS AND MACHINE INTELLIGENCE,
//   VOL. 32,   NO. 9,   SEPTEMBER 2010
// Seungkyu Lee, Student Member, IEEE, and Yanxi Liu, Senior Member
//--------------------------------------------------------------
//
//
// RotationCenter.h
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef __center_detection__
#define __center_detection__
#include <contrib.hpp>
#include <highgui.hpp>
#include <dirent.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

#define SAMPLING 16
#define MIN_VAL -100000

class RotationCenter
{
    public:
	    //costruttore
        RotationCenter(){};
		//distruttore
        ~RotationCenter(){};

    private:
	    //metodo per effettuare la Freize-Expansion
        Mat imageFE(Mat img,int xc,int yc,double step,int R);
		//metodo per calcolare l'energia spettrale
        Mat SpectralImage(Mat img);
		// metodo che implemente la DFT riga per riga
        Mat *rowDft(Mat row);
		//metodo che calcola l'energia spettrale riga per riga, utilizzando
		//i coefficienti calcolati tramite DFT
        Mat rowSpectral(Mat *planes);
		//metodo che determina il valore dell'intensità luminosa dell'RSS
        double RSSik(Mat spectral);
		//metodo per mostrare la DFT in falsi colori
        Mat showFalseColor(Mat img,string windows_name);
		//metodo che restituisce il valore mediano
        double medianValue(double *val,int size);
		//metodo che determina le fasi per i BF
        double *imageRowsDft(Mat img);
		//metodo che permette la determinazione dei BidirectionalFlow
        int *bidirectionalFlow(Mat img,int xc,int yc,double &phase);

    public:
	    //implementazione dell'RSS map
        Mat RSS(Mat img);
		//metodi per mostrare l'RSS e l'SSD in falsi colori
        Mat showRSS(Mat img,string windows_name,int sx,int sy);
        Mat showSSD(Mat img,string windows_name);
		//implementazione dell'SSD map
        Mat SSD(Mat img,int &xc,int &yc);
		//metodo utilizzato per segmentare la FE
        Mat feSeg(Mat img,int cx,int cy);
		//metodo per trovare il massimo locale e l'immagine in scala di grigio
        Mat getCenter(Mat rss, Point &maxloc);
		//metodo per determinare i fold
        int FindFold(double *row);
		//metodo per determinare le bande quindi le regioni
        int SupportingRegion(int line_seg[],int region_start[],int region_stop[],
		                     int mean_region_val[],int band_value[],int R);
		//metodo per determinare il gruppo di simmetria
        void CheckSimmetry(char group[],Mat segFES[],int j,int region_fold[]);
};
#endif
