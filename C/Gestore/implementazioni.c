#include <stdlib.h>
#include <stdio.h>
#include"prototipi.h"
/*
 =======================================================================================================================
    Implementazione della funzione per il calcolo del totale del costo delle chiamate
    INput:
          prende in input la lista con le chiamate effettuate dall ID in un dato giorno eil numero di kiamate e il costo
    OUTPUT:
           darà in out il costo totale delle chiamate effettuate dal suddetto ID
 =======================================================================================================================
 */
float totale_costo_chiamate(chiamata *x, int n, float costo)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	float	totaledurata = 0, totale = 0;
	int		i;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
totaledurata = 0;
totale=0;/*azzero il totale ad ogni successiva chiamata alla funzione altrimenti si porterebbe dietro tutte le somme delle chiamate effettuate in precedenza*/
	for(i = 0; i < n; i++)
	{
		
		totaledurata += x[i].durata;
	}
   //calcolo il totale del costo dividendo la durata totale per il costo effettivo

	totale = totaledurata / costo;

	return totale;
}

/*
 =======================================================================================================================
    Procedura di Stampa della Struttura dati
    INPUT:
          Lista chiamate, numero delle chiamate caricate
    
 =======================================================================================================================
 */
void stampa(chiamata *x, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf(" %d Id Chiamante: %10.0lf \n", i + 1, x[i].id_chiamante);
		printf(" ID Ricevente : %10.0lf \n", x[i].id_ricevente);
		printf(" Durata della chiamata: %2.2f \n", x[i].durata);
	}
}

/*
 =======================================================================================================================
    Procedura di caricamento della Struct
    INPUT:
          Id chiamante, ID ricevente, Durata chiamata
          numero delle chiamate da caricare
    Out: darà la struttura caricata 
    
 =======================================================================================================================
 */
void carica(chiamata *tel, int nn)
{
     int i;
	fflush(stdin);	/* Istruzione che serve a scaricare il buffer */
	for(i = 0; i < nn; i++)
	{
		printf("Inserisci l'ID del %d Chiamante \n", i + 1);
		scanf("%lf", &tel[i].id_chiamante);
		printf("Inserisci l'ID del Ricevente \n");
		scanf("%lf", &tel[i].id_ricevente);
		printf("Inserisci la durata della chiamata \n");
		scanf("%f", &tel[i].durata);
	}
}

/*
 =======================================================================================================================
    Funzione per il calcolo del massimo
    INPUT:
          lista chiamate in un dato giorno, numero delle chiamate
    OUTPUT:
           darà l INDICE della chiamata che è durata di piu che risulterà essere poi uguale alla "piu costosa"
 =======================================================================================================================
 */
int massimo(chiamata *x, const int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	float	max = x[0].durata;
	int		i, indice_max = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 1; i < n; i++)
	{
		if(x[i].durata > max)
		{
			max = x[i].durata;	/* aggiorno il massimo */
			indice_max = i;		/* conservo l'indice della chiamata piu' lunga */
		}
	}

	return indice_max;			/* Restituisco l'indice e non il massimo poiche servirà per stampare le
								 * informazioni al riguardo */
}

/*
 =======================================================================================================================
    Procedura della ricerca sequenziale
    INPUT:
          prende in input la lista delle chiamate, il numero di chiamate, la chiave da ricercare
    OUTPUT:
           darà una struttura di appoggio (TEMP) che avrà le informazioni riguardo alla chiave ricercata se l esito è 
           stato positivo, viceversa se la chiave non fosse presente K(la dimensione della struttura di appoggio) sarà 0.
 =======================================================================================================================
 */
void ricerca_sequenziale(chiamata *x, int n, int *k, double chiave, chiamata *temp)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
         
		/* confronto l id chiamante con la mia chiave da ricercare */
		if(x[i].id_chiamante == chiave)
		{
			temp[*k] = x[i];	/* se sono uguali carico in una struttura di appoggio l'i-esima chiamata */
			(*k)++; /* aggiorno il puntatore che utilizzo come indice per la struttura di appoggio */
		}
	}
}
