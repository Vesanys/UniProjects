/*
 * Dischi Si vuole simulare la gestione automatizzata di un archivio di dischi
 * musicali. Si suppone di avere un archivio di massimo 100 dischi identificati
 * dal titolo, nome dell'autore o gruppo, da un codice identificativo e dal
 * prezzo di prestito. Un disco può essere presente o in prestito. Permettere
 * all'utente di: - Inserire un nuovo disco nell'archivio (automaticamente
 * gli viene assegnato un codice). 
 *- Visualizzare tutti i dischi di uno stesso autore o gruppo.
 * -Richiedere un disco tramite il codice (verificare se esso
 * è presente o è in prestito).
 *- Restituire un disco tramite il codice.
 * - Cercare nell'archivio il cd più costoso (usare un approccio
 * divide-etimpera) 
 *Provvedere all'implementazione dell'algoritmo per la
 * simulazione del negozio di dischi.
 *Effettuare almeno un test per ognuna delle
 * opzioni richieste dall'utente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "header.h"


/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	disco	x[MAX],temp[MAX];
	int		risp, n, trovato, indice, codice,k=0;
	char	nome[20];
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Scegliere l'operazione da eseguire\n");
		printf("1. Inserire nuovo disco\n");
		printf("2. Visualizzare dischi di un dato autore\n");
		printf("3. Richiedere disco  \n");
		printf("4. Restituire disco  \n");
		printf("5. Disco piu' costoso \n");
		printf("6. Exit\n");
		scanf("%d", &risp);

		switch(risp)
		{
		case 1:
			do
			{
				printf("Quanti dischi vuoi caricare? \n");
				scanf("%d", &n);
			} while(n < 0);
			fflush(stdin);
			carica(x, n);
			system("cls");
			break;

		case 2:
			{
				
				printf("Inserisci il nome dell'autore da ricercare\n");
				scanf("%s", &nome);
			
				ricerca_sequenziale(x,n,&k,nome,temp);
				if(k==0){
                         printf("Non sono presenti dischi dell'autore richiesto!\n");
                         system("pause");
                         system("cls");
                         }
				else{
				                    printf("elenco dischi:%d\n",k);
				                    stampa(temp,k);
				                    system("pause");
				                    system("cls");
                                    }
			}
			break;

		case 3:
			{
				stampa(x, n);
				printf("inserisci codice del disco da richiedere: ");
				scanf("%d", &codice);
				if(x[codice].flag == 1)
				{
					printf("Disco presente\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("Il disco richiesto risulta in prestito\n\n");
					system("pause");
					system("cls");
				}
			}
			break;

		case 4:
			{
				stampa_con_flag(x, n);
				printf("Inserire il codice del disco da restituire: ");
				scanf("%d", &codice);
				if(x[codice].flag == 0)
				{
					x[codice].flag = 1;
					printf("Operazione effettuata con successo! Disco ora disponibile!\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("Disco gia' disponibile!!\n");
					system("pause");
					system("cls");
				}
			}
			break;

		case 5:
			{
				indice = massimo(x, n);
				printf("Il cd piu' costoso e': \n");
				printf("TITOLO: %s\n", x[indice].titolo);
				printf("AUTORE: %s\n", x[indice].nome_autore);
				printf("PREZZO: %2.2f\n", x[indice].prezzo);
				system("pause");
				system("cls");
			}
			break;

		case 6:
			break;

		default:
			break;
		}
	} while(risp != 6);

	system("pause");
	return 0;
}
