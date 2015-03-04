/*$T indentinput.c GC 1.140 05/26/11 08:59:26 */

/* Funzioni.c */
#include <stdio.h>		/* Inclusione della libreria standard di input/output, utile per le principali funzioni del C */
#include <stdlib.h>		/* Inclusione della libreria standard lib, utile per la dichiarazione di funzioni e costanti di
						 * utilit� generale */
#include <time.h>		/* Inclusione della time, utile per l'accesso standardizzato alle funzioni di acquisizione e
						 * manipolazione del tempo, in realta' essa restituisce il valore dell'ora riportato
						 * dall'orologio interno del calcolatore */

#include "funzioni.h"	/* Inclusione dell'header file, esso contiene i prototipi delle funzioni specificate in questo
						 * file, ovvero funzioni.c */

#define MAX 40			/* Definisco una costante di nome MAX, per effetto di questa definizione nel programma verr�
						 * assegnato il valore 40 ogni volta che comparira' MAX */

/*
 =======================================================================================================================
    Sviluppo funzioni ;
    Procedura che consente di mischiare le carte in modo casuale
 =======================================================================================================================
 */
void mischia(Carta *mazzo, int volte)
{
	/*~~~~~~~~*/
	int k, i, j;
	/*~~~~~~~~*/

	srand(time(NULL));	/* Genera ad ogni esecuzione del programma una diversa sequenza di numeri pseudocasuali */
	for(k = 0; k < (volte * MAX); k++)
	{
		i = rand() % MAX;
		j = rand() % MAX;
		scambia_carte(mazzo, i, j);
	}
}

/*
 =======================================================================================================================
    Procedura che consente di scambiare le carte
 =======================================================================================================================
 */
void scambia_carte(Carta *mazzo, int i, int j)
{
	/*~~~~~~~~~*/
	Carta	temp;
	/*~~~~~~~~~*/

	temp = mazzo[i];
	mazzo[i] = mazzo[j];
	mazzo[j] = temp;
}

/*
 =======================================================================================================================
    Funzione che consente il controllo del punteggio dei giocatori
 =======================================================================================================================
 */
int controllo_punteggio(float tot)
{
	/*~~~~~*/
	int fine;
	/*~~~~~*/

	if(tot > 7.5)		/* Costrutto di selezione che verifica se il tot e' > di 7.5 */
	{
		printf("Hai sballato!!!\n");
		fine = 1;
	}
	else if(tot == 7.5) /* Costrutto di selezione che verifica se il tot e' = a 7.5 */
	{
		printf("Complimenti hai fatto 7 e mezzo!!!\n");
		fine = 1;
	}
	else			/* Costrutto di selezione che verifica se il tot e' < di 7.5 */
	{
		printf("Il tuo totale parziale e' %f ...\nPotresti ancora fare 7 e mezzo..\n", tot);
		fine = 0;
	}

	return fine;	/* ritorna fine */
}

/*
 =======================================================================================================================
    Funzione che consente di aggiornare il punteggio dei giocatori
 =======================================================================================================================
 */
float aggiorna_punteggio(Carta carta, float punteggio)
{
	if(carta.valore >= 8)			/* Costrutto di selezione per l'aggiornamento del punteggio */
	{
		punteggio += 0.5;			/* aggiornamento punteggio */
		printf("Il totale parziale e' %1.1f\n", punteggio);
	}
	else
	{
		punteggio += carta.valore;	/* aggiornamento punteggio */
		printf("Il totale parziale e' %1.1f\n", punteggio);
	}

	return punteggio;	/* ritorna punteggio */
}

/*
 =======================================================================================================================
    Procedura che consente di visualizzare la carta scelta
 =======================================================================================================================
 */
void stampa_carta(Carta carta)
{
	/*~~~~~~~~~~*/
	char	*seme;
	/*~~~~~~~~~~*/

	switch(carta.seme)
	{
	case 0:		seme = "denari"; break;
	case 1:		seme = "bastoni"; break;
	case 2:		seme = "spade"; break;
	case 3:		seme = "coppe"; break;
	default:	break;
	}

	printf("La carta scelta e': %d %s\n", carta.valore, seme);
}

/*
 =======================================================================================================================
    Funzione che consente di controllare il gioco
 =======================================================================================================================
 */
float gioca(char *giocatore, float punteggio_iniziale, Carta *mazzo, int *carte_uscite)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		indice_mia_carta, scelta = 0, fine, finish = 0, ripeti = 1; /* Dichiarazione e inizializzazione delle
																		 * variabili */
	float	totale = punteggio_iniziale;			/* Assegnazione di punteggio_iniziale alla variabile totale */
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	printf("Gioca il giocatore %s\n", giocatore);	/* Visualizzazione su schermo del nome del giocatore */
	indice_mia_carta = pesca_carta(carte_uscite);
	stampa_carta(mazzo[indice_mia_carta]);			/* Visualizzazione su schermo della carta */

	while(finish == 0)		/* Ciclo di iterazione, utile per */
	{
		totale = aggiorna_punteggio(mazzo[indice_mia_carta], totale);

		while(ripeti == 1)	/* Ciclo di iterazione */
		{
			printf("Vuoi un'altra carta?\n1)Si\n2)No\n");	/* Richiesta e visualizzazione su schermo della scelta da
															 * effettuare */
			scanf("%d", &scelta);

			if(scelta == 1) /* Costrutto di selezione per la richiesta di un'altra carta */
			{
				printf("Hai richiesto un'altra carta\n");	/* Visualizzazione su schermo della scelta effettuata */

				indice_mia_carta = pesca_carta(carte_uscite);
				stampa_carta(mazzo[indice_mia_carta]);		/* Visualizzazione su schermo della carta */
				totale = aggiorna_punteggio(mazzo[indice_mia_carta], totale);	/* Confronto per il valore della carta */
				fine = controllo_punteggio(totale); /* Controllo del punteggio */

				if(fine == 1)
				{
					ripeti = 0;
					finish = 1;
				}
				else
				{
					ripeti = 1;
				}
			}	/* Chiusura if per la richiesta di un'altra carta */
			else if(scelta == 2)	/* Costrutto di selezione, utile se si decide di non richiedere un'altra carta */
			{
				printf("Hai scelto di fermarti, il tuo punteggio finale e' %f\n", totale);	/* Visualizzazione su
																							 * schermo della scelta
																							 * effettuata */
				ripeti = 0;
				finish = 1;
			}
			else
			{
				printf("Scelta non valida!!!\n");	/* Visualizzazione su schermo di un messaggio di Errore, nel caso
													 * in cui sia stato inserito un valore non valido */
			}
		}	/* Chiusura secondo while */
	}		/* Chiusura primo while */

	system("pause");
	system("cls");

	return totale;
}

/*
 =======================================================================================================================
    Funzione che consente il controllo delle carte gia' uscite
 =======================================================================================================================
 */
int pesca_carta(int *carte_uscite)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int carta_gia_uscita = 1, indice_carta = 0; /* Dichiarazione e inizializzazione delle variabili */
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	while(carta_gia_uscita == 1)	/* Ciclo di iterazione */
	{
		indice_carta = rand() % MAX;

		if(carte_uscite[indice_carta] == 1)
			carta_gia_uscita = 1;
		else
			carta_gia_uscita = 0;
	}

	carte_uscite[indice_carta] = 1;

	return indice_carta;			/* Ritorna indice_carta */
}
