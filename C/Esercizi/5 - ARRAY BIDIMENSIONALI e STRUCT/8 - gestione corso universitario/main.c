#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere un programma per la gestione delle presenze a un corso unversitario. Ogni studente e indetificato dal
    nome, dal cognome e dalla matricola. Il corso ha 10 studenti ed e composto complessivamente da 15 lezioni.
    Permettere di visualizzare i nomi degli studenti presenti ad una data lezione e lo studente che ha piu presenze su
    tutte le lezioni.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct studente
{
	int		matricola;
	char	nome[50];
	char	cognome[50];
	int		presenz[15];
} Studente;

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Studente	stud[MAX];
	int			presenze, cont = 0, scelta, risp = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Benvenuto al corso universitario!\n");
		printf("Scegli l'operazione da eseguire \n");
		printf("1. Inizia il corso universitario di 15 lezioni \n");
		printf("2. Visualizza studenti presenti in una data lezione \n");
		printf("3. Visualizza studente con piu presenze \n");
		printf("4. Esci\n");
		printf("Inserisci scelta --> ");
		scanf("%d", &scelta);

		switch(scelta)
		{
		case 1:
			for(int j = 0; j < 15; j++)
			{
				do
				{
					printf("Quanti studenti sono presenti alla %d lezione? : ", j + 1);
					scanf("%d", &presenze);
				} while(presenze < 0 || presenze > max);

				for(int i = 0; i < presenze; i++)
				{
					fflush(stdin);
					printf("inserisci nome del %d studente presente :", i + 1);
					gets(stud[i].nome);
					printf("inserisci cognome del %d studente presente :", i + 1);
					gets(stud[i].cognome);
					printf("inserisci matricola del %d studente presente :", i + 1);
					scanf("%d", &stud[i].matricola);
					do
					{
						printf("Flag di presenza: 1 Presente 0 Assente :");
						scanf("%d", &stud[i].presenz);
					} while(stud[i].presenz < 0 || stud[i].presenz > 1);
				}
			}
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		default:
			break;
		}

		printf("Vuoi fare un altra operazione?\n");
		scanf("%d", &risp);
	} while(scelta < 1 || scelta > 4 || risp);

	system("PAUSE");
	return EXIT_SUCCESS;
}
