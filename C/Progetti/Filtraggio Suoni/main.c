/*$T indentinput.c GC 1.140 05/26/11 08:59:15 */

/*
 * Filtraggio Suoni. Dati due array monodimensionali x ed y di dimensione 1xn.
 * Ognuno contiene le informazioni relative ad un file sonoro. Si chiede di
 * implementare una funzione che permette di ottenere la mistura dei due segnali
 * secondo la seguente relazione: z[i] = A[0]*x[i]+A[1]*y[i], dove A e un array di
 * dimensioni 1x2 i cui valori sono compresi nell'intervallo [0,1].
 * Successivamente si chiede di implementare il filtraggio della mistura z[i] in
 * modo da ottenere una nuovo suono filtrato y[i] = sommatoria che va da k=0 a 9
 * di C[k]z[i+k]. dove C e un vettore di coefficienti inseriti dall'utente e di
 * dimensione 10. Per ottenere il filtraggio bisogna aggiungere degli zero alla
 * fine della sequenza z[i]. I suoni vengono inizializzati casualmente con valori
 * float nell'intervallo [-10, 10] e i coefficienti vengono inseriti dall'utente.
 * Filtraggio Suoni.
 */
#include <stdio.h>		/* Inclusione della libreria standard di input/output, utile per le principali funzioni del C */
#include <stdlib.h>		/* Inclusione della libreria standard lib, utile per la dichiarazione di funzioni e costanti di
						 * utilit� generale */
#include <time.h>		/* Inclusione della time, utile per l'accesso standardizzato alle funzioni di acquisizione e
						 * manipolazione del tempo, in realta' essa restituisce il valore dell'ora riportato
						 * dall'orologio interno del calcolatore */

#include "funzioni.h"	/* Inclusione dell'header file, esso contiene i prototipi delle funzioni specificate in
						 * funzioni.c */

#define N	10			/* Definisco una costante di nome N, per effetto di questa definizione nel programma verr�
						 * assegnato il valore 10 ogni volta che comparira' N */
#define K	10			/* Definisco una costante di nome K, per effetto di questa definizione nel programma verr�
						 * assegnato il valore 10 ogni volta che comparira' K */

/*
 =======================================================================================================================
    Inizio programma
 =======================================================================================================================
 */
main() /* Main: funzione principale che permette di eseguire un programma */
{

	/*~~~~~~~~~~~~~~~~~*/
	/* Dichiarazione delle variabili */
	float	x[N] = { 0 },
	y[N] = { 0 },
	z[N + K] = { 0 },
	C[K] = { 0 };		/* vettore di coefficienti inseriti dall'utente di dimensione 10 */
	int		i;
	/*~~~~~~~~~~~~~~~~~*/

	/*
	 * Avendo due Array monodimensionali x ed y, i quali contenono informazioni
	 * relative ad un file sonoro, inizializziamo i suoni in modo casuale con valori
	 * float, nell'intevallo [-10,10
	 */
	srand(time(NULL));	/* Genera ad ogni esecuzione del programma una diversa sequenza di numeri pseudocasuali */

	printf("I valori inizializzati casualmente di x e y sono:\n");

	for(i = 0; i < N; i++) /* Ciclo iterativo */
	{
		x[i] = -10.0F + 20.0F * (float) rand() / (float) RAND_MAX;	/* Utile per la generazione di numeri pseudocasuali
																	 * di tipo reale poiche' float, uniformemente
																	 * distribuiti nell'intervallo [-10, 10]. */
		y[i] = -10.0F + 20.0F * (float) rand() / (float) RAND_MAX;	/* Utile per la generazione di numeri pseudocasuali
																	 * di tipo reale poiche' float, uniformemente
																	 * distribuiti nell'intervallo [-10, 10]. */
		printf("x[%d]: %f\t y[%d]: %f\n", i, x[i], i, y[i]);		/* Visualizzazione sullo schermo dei valori x ed y
																	 * inizializzati casualmente nell'intervallo [-10,
																	 * 10] */
	}

	/*
	 * Implementazione della Funzione che permette di ottenere la mistura di due
	 * segnali, secondo la seguente relazione: z[i]=A[0]*x[i]+A[1]*y[i]
	 */
	mistura_segnali(x, y, z, N);	/* Chiamata alla Funzione mistura_segnali */

	printf("Mistura di due segnali ottenuta tramite la Funzione z:\n"); /* Visualizzazione sullo schermo della mistura
																		 * dei due segnali ottenuta tramite la Funzione
																		 * z */
	stampa(z, N);			/* Chiamata alla Funzione stampa che permette la visualizzazione di z */
	inserisci_valori(C, N); /* Chiamata alla Funzione inserisci_valori */
	filtraggio(C, y, z, N, K);	/* Chiamata alla Funzione filtraggio */

	printf("Valori del nuovo suono Filtrato y:\n"); /* Vengono di seguito riportati i valori del nuovo suono Filtrato,
													 * ovvero: y[i] ottenuti tramite il filtraggio della mistura z[i] */
	stampa(y, N);	/* Chiamata alla Funzione stampa che permette la visualizzazione di y */
}
