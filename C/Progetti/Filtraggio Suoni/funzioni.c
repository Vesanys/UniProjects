
/* Funzioni.c */
#include <stdio.h>		    /* Inclusione della libreria standard di input/output, utile per le principali funzioni del C */
#include <stdlib.h>		/* Inclusione della libreria standard lib, utile per la dichiarazione di funzioni e costanti di
                            * utilit� generale */
#include <time.h>		    /* Inclusione della time, utile per l'accesso standardizzato alle funzioni di acquisizione e
                            * manipolazione del tempo, in realta' essa restituisce il valore dell'ora riportato
                            * dall'orologio interno del calcolatore */

#include "funzioni.h"	/* Inclusione dell'header file, esso contiene i prototipi delle funzioni specificate in questo
                            * file, ovvero funzioni.c */

#define N	10			/* Definisco una costante di nome N, per effetto di questa definizione nel programma verr�
                            * assegnato il valore 10 ogni volta che comparira' N */
#define K	10			/* Definisco una costante di nome K, per effetto di questa definizione nel programma verr�
                            * assegnato il valore 10 ogni volta che comparira' K */

/*
 =======================================================================================================================
    Sviluppo funzioni ;
    Procedura che permette di inserire i valori all'utente
 =======================================================================================================================
 */
void inserisci_valori(float *C, int dim)
{
	/*~~*/
	int k;
	/*~~*/

	for(k = 0; k < dim; k++)	/* Ciclo iterativo */
	{
		printf("L'utente deve inserire %d valore di C: ", k + 1);
		scanf("%f", &C[k]);
	}
}

/*
 =======================================================================================================================
    Procedura che consente di la visualizzazione dei valori
 =======================================================================================================================
 */
void stampa(float *v, int dim)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < dim; i++)	/* Ciclo iterativo */
	{
		printf("[%d]: %f\n", i, v[i]);
	}
}

/*
 =======================================================================================================================
    Procedura che consente la mistura dei due segnali ottenuti tramite la funzione z
 =======================================================================================================================
 */
void mistura_segnali(float *x, float *y, float *z, int len)
{
	/*~~~~~~~~~*/
	float	A[2];
	int		i;
	/*~~~~~~~~~*/

	/* A e' un Array i cui valori di amplificazione sono compresi nell'intervallo [0,1] */
	srand(time(NULL));	/* Genera ad ogni esecuzione del programma una diversa sequenza di numeri pseudocasuali */

	A[0] = (float) rand() / (float) RAND_MAX;	/* Utile per la generazione di numeri pseudocasuali di tipo reale
												 * poiche' float, uniformemente distribuiti nell'intervallo [0,1]. */

	A[1] = (float) rand() / (float) RAND_MAX;	/* Utile per la generazione di numeri pseudocasuali di tipo reale
												 * poiche' float, uniformemente distribuiti nell'intervallo [0,1]. */

	for(i = 0; i < N; i++)	/* Ciclo iterativo */
		z[i] = A[0] * x[i] + A[1] * y[i];	/* formula z[i] */
}

/*
 =======================================================================================================================
    Procedura che consente il Filtraggio y[i]
 =======================================================================================================================
 */
void filtraggio(float *C, float *y, float *z, int len, int len_C)
{

	/*~~~~~~~~~*/
	/* Implementazione sommatoria di y[i] */
	int		i, j;
	float	sum;
	/*~~~~~~~~~*/

	for(i = 0; i < N; i++)		/* Ciclo iterativo */
	{
		sum = 0;

		for(j = 0; j < K; j++)	/* Ciclo iterativo */
		        sum += C[j] * z[i + j];


		y[i] = sum;
	}
}
