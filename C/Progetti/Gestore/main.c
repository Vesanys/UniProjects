/*$T Vitanostra Josef Nat: 0124/224 01/13/11 17:06:39 

Si deve gestire un gestore telefonico per 31 giorni, facendo scegliere all utente di inserire chiamate per un max di
10 al giorno con un costo di 10 centesimi al minuto. Ho permesso di inserire le chiamate, visualizzare informazioni riguardo
alle chiamate effettuate da un certo ID, visualizzare il costo totale di un dato ID(tutte le chiamate efettuate in quel giorno) 
e la chiamata piu costosa di un dato ID in quel giorno. 



*/


#include <stdlib.h>
#include <stdio.h>
#include "prototipi.h"
#define MAX 10

/*
 -----------------------------------------------------------------------------------------------------------------------
    Chiamate telefoniche Si vuole simulare  l'archivio  di  chiamate  di  un  gestore telefonico. L'archivio risulta
    mensile (31 giorni) . Ogni giorno vengono effettuate al massimo 10 chiamate e il costo al minuto di una chiamata
    è di 10 centesimi. Ogni chiamata è  identificata  dal numero  chiamante,  il numero ricevente e la  durata della
    chiamata.  Provvedere  all' implementazione  dell' algoritmo  per  la   simulazione  dell' archivio.  Permettere,
    inoltre, all' utente di : 
             *  Inserire una chiamata in un dato giorno 
             *  Dato un numero telefonico visualizzare tutte le chiamate con le relative informazioni in un singolo giorno 
             *  Dato un numero telefonico vedere il costo totale delle chiamate. 
             *  Visualizzare le informazioni relative alla chiamata più costosa. 
             
             L'archivio può anche essere inizializzato con informazioni casuali. 
             Effettuare almeno due test per ognuna delle opzioni dell'utente. ;
    
 -----------------------------------------------------------------------------------------------------------------------
 */

/*
 =======================================================================================================================
    MAIN
 =======================================================================================================================
 */
int main()
{

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/* Fase dichiarativa */
	chiamata	x[MAX], temp[MAX];
	int			risp, n, trovato, indice, k = 0, cont = 0;
	double      id;
	float		costo_chiamata = 10, tot = 0, costo_c = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Scegliere l'operazione da eseguire\n");
		printf("1. Inserire chiamata\n");
		printf("2. Ricerca chiamata in base all' ID\n");
		printf("3. Costo totale di un dato ID  \n");
		printf("4. Chiamata piu costosa  \n");
		printf("5. Exit \n");
		printf("Inserisci scelta -> ");
		scanf("%1d", &risp);

		/* costrutto switch sulla scelta */
		switch(risp)
		{
		case 1:
             
			
			if(cont < 31)
			{
            cont++; /* incremento il conto dei giorni */
			printf("%d Giorno\n", cont);
				do
				{
					printf("Quante chiamate vuoi caricare? \n");
					scanf("%d", &n);
				} while(n < 0 || n > MAX);

				/* controllo che non si effettuino piu di 10 telefonate o meno di 0 */
				fflush(stdin);	/* istruzione per scaricare il buffer */
				carica(x, n);	/* chiamata alla procedura di caricamento */
                system("pause");
				system("cls");	/* istruzione per effettuare un clear dello screen */
			}
				/* avviso nel caso
			     * in cui finisse
				 * il mese di
				 * gestione */
			else{
				printf("Tempo di gestione esaurito! impossibile caricare ulteriori chiamate \n");
			    system("pause");
                system("cls");
                }	
            break;

		case 2:
			{
				stampa(x, n);	/* chiamata alla procedura di stampa */
				printf("Inserisci l'ID del utenza da ricercare\n");
				scanf("%lf", &id);

				ricerca_sequenziale(x, n, &k, id, temp);	/* chiamata alla procedura della ricerca sequenziale per
															 * caricare in una struttura di appoggio tutte le chiamate
															 * effettuate da un dato ID */
															
				if(k == 0)	/* soluzione del caso in cui non vi siano riscontri della ricerca */
				{
					printf("Non sono presenti ID dell'utenza richiesta!\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("Elenco chiamate dell ID richiesto: \n");
					stampa(temp, k);	/* Stampa delle informazioni relative alle telefonate effettuate da un dato ID */
					system("pause");
					system("cls");
				}
			}
			break;

		case 3:
			{
                  tot=0;
				stampa(x, n);
				printf("Inserisci l'ID del utenza da ricercare\n");
				scanf("%lf", &id);
				ricerca_sequenziale(x, n, &k, id, temp);	/* ricerca sequenziale */
				tot = totale_costo_chiamate(temp, k, costo_chiamata);	/* chiamata della funzione per il calcolo del
																		 * totale del costo delle chiamate */
				printf("Il totale costo delle chiamate effettuate e' : %2.2f euro  \n", tot);
				
				system("pause");
				system("cls");
			}
			break;

		case 4:
			{
				indice = massimo(x, n); /* chiamata della funzione per il calcolo della chiamata con il costo maggiore
										 * che combacierà con quella con la durata maggiore */
				printf("L'Id che ha effettuato la chiamata piu costosa e': \n");
				printf("Id chiamante: %10.0lf\n", x[indice].id_chiamante);
				printf("Id ricevente: %10.0lf\n", x[indice].id_ricevente);
				printf("Durata telefonata: %2.2f Minuti\n", x[indice].durata);
				costo_c = x[indice].durata / costo_chiamata;
				printf("Il costo della chiamata piu lunga e' stato %2.2f\n", costo_c);
				system("pause");
				system("cls");
			}

		case 5:
			break;

		default:
			break;
		}
	} while(risp != 5);

	system("pause");
	return 0;
}
