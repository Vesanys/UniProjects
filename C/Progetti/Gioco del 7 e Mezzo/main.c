/*$T indentinput.c GC 1.140 05/26/11 08:59:35 */

/*
 * Gioco del 7 e �. Viene richiesto di inserire i nomi dei due giocatori. Dopo
 * aver inserito i nomi dei due giocatori, verr� � chiesto il numero di volte
 * che si desidera mischiare il mazzo di carte. Dopo aver mischiato il mazzo di
 * carte, il primo giocatore inizia a giocare con una carta estratta in modo
 * casuale: --> Se il punteggio e' pari a 7 e �, allora il primo giocatore Ha
 * Vinto la partita. --> Se il punteggio supera 7 e �, allora il primo giocatore
 * Ha Perso la partita. Il primo giocatore pu� ora decidere di non richiedere
 * un'alta carta. Nel caso in cui il primo giocatore decida di non richiedere
 * un'altra carta, il turno passa al secondo giocatore. Ora e' il turno del
 * secondo giocatore, il quale inizia a giocare anch'esso con una carta estratta
 * in modo casuale: Il secondo giocatore pu� ora decidere se richiedere un'alta
 * carta. --> Se il punteggio e' pari a 7 e �, allora il secondo giocatore Ha
 * Vinto la partita. --> Se il punteggio supera 7 e �, allora il secondo
 * giocatore Ha Perso la partita. Il secondo giocatore pu� ora decidere di non
 * richiedere un'alta carta. Nel caso in cui il secondo giocatore decida di non
 * richiedere un'altra carta, il sistema provvede a comparare il punteggio del
 * primo e secondo giocatore, il giocatore cha ha un punteggio pi� grande e che
 * non supera 7 e � Vince. Gioco del 7 e �.
 */
#include <stdio.h>		/* Inclusione della libreria standard di input/output, utile per le principali funzioni del C */
#include <stdlib.h>		/* Inclusione della libreria standard lib, utile per la dichiarazione di funzioni e costanti di
						 * utilit� generale */
#include <time.h>		/* Inclusione della time, utile per l'accesso standardizzato alle funzioni di acquisizione e
						 * manipolazione del tempo, in realta' essa restituisce il valore dell'ora riportato
						 * dall'orologio interno del calcolatore */

#include "funzioni.h"	/* Inclusione dell'header file, esso contiene i prototipi delle funzioni specificate in
						 * funzioni.c */

#define MAX 40			/* Definisco una costante di nome MAX, per effetto di questa definizione nel programma verr�
						 * assegnato il valore 40 ogni volta che comparira' MAX */

/*
 =======================================================================================================================
    Inizio programma
 =======================================================================================================================
 */
int main()	/* Main: funzione principale che permette di eseguire un programma */
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Carta	mazzo[MAX] =
	{
		{ 1, denari },
		{ 2, denari },
		{ 3, denari },
		{ 4, denari },
		{ 5, denari },
		{ 6, denari },
		{ 7, denari },
		{ 8, denari },
		{ 9, denari },
		{ 10, denari },
		{ 1, bastoni },
		{ 2, bastoni },
		{ 3, bastoni },
		{ 4, bastoni },
		{ 5, bastoni },
		{ 6, bastoni },
		{ 7, bastoni },
		{ 8, bastoni },
		{ 9, bastoni },
		{ 10, bastoni },
		{ 1, spade },
		{ 2, spade },
		{ 3, spade },
		{ 4, spade },
		{ 5, spade },
		{ 6, spade },
		{ 7, spade },
		{ 8, spade },
		{ 9, spade },
		{ 10, spade },
		{ 1, coppe },
		{ 2, coppe },
		{ 3, coppe },
		{ 4, coppe },
		{ 5, coppe },
		{ 6, coppe },
		{ 7, coppe },
		{ 8, coppe },
		{ 9, coppe },
		{ 10, coppe }
	};
	/* Dichiarazione dei giocatori */
	char	giocatore1[MAX], giocatore2[MAX];
	/* Dichiarazione delle variabili */
	int		quante_volte, carte_uscite[MAX], i, num_partite = 10;
	float	punteggio1 = 0, punteggio2 = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/*
	 * Inizializza il generatore e genera un numero casuale, essa e'definita nella
	 * libreria stdlib.h
	 */
	srand(time(NULL));

	/* Inserimento e Visualizzazione dei nomi dei due giocatori */
	printf("Inserisci il nome del primo giocatore: ");
	scanf("%s", &giocatore1);
	printf("Inserisci il nome del secondo giocatore: ");
	scanf("%s", &giocatore2);

	/* Di seguito viene chiesto all'utente quante volte di desidera mischiare il mazzo */
	printf("Quante volte vuoi mischiare il mazzo?: ");
	scanf("%d", &quante_volte);

	/* Chiamata alla funzione mischia */
	mischia(mazzo, quante_volte);

	/* Ciclo di iterazione che permette di determinare il numero delle partite */
	for(i = 0; i < num_partite; i++)
	{
		printf("----------------------------------------\n");
		printf("Partita Numero %d\n", i + 1);
		punteggio1 = gioca(giocatore1, punteggio1, mazzo, carte_uscite);

		punteggio2 = gioca(giocatore2, punteggio2, mazzo, carte_uscite);

		/* Azzero il punteggio se i giocatori hanno sballato */
		if(punteggio1 > 7.5) punteggio1 = 0;
		if(punteggio2 > 7.5) punteggio2 = 0;

		/* Visualizzazione del Vincitore o del Pareggio */
		if(punteggio1 > punteggio2)
			printf("Vince il giocatore %s\n", giocatore1);
		else
		{
			if(punteggio1 < punteggio2)
				printf("Vince il giocatore %s\n", giocatore2);
			else
				printf("Partita conclusa con pareggio\n\n");
		}

		punteggio1 = 0;
		punteggio2 = 0;
	}	/* Chiusura for sul numero delle partite */

	system("pause");
	return 0;
}
