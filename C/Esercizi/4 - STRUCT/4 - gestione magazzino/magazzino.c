#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 5

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere un programma per la gestione di un magazzino di prodotti elettronici. Il maga- zzino contiene al massimo 5
    prodotti identificati da un codice, nome, dal prezzo e dalla quantita. Il magazzino viene gestito per 10 giorni
    complessivi. Ogni giorno l'utente puo acquistare al massimo 5 prodotti se sono disponibili. Visualizzare il
    prodotto piu venduto nei 10 giorni.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct magazzino
{
	int		codice;
	char	nome[10];
	float	prezzo;
	int		quantita;
} prodotto;

/* dichiarazione prototipi dei sottoprogrammi */
void	carica_prodotti(prodotto *, int *);
void	acquista_prodotto(prodotto *, const int, int *, int *, int *, int *, int *, int *);
void	stampa_prodotti(prodotto *, const int);
int		calcola_massimo(int *, int *, int *, int *, int *, int *);

/*
 =======================================================================================================================
    elaborazione sottoprogrammi
 =======================================================================================================================
 */
int calcola_massimo(int *max, int *cont1, int *cont2, int *cont3, int *cont4, int *cont5)
{
	*max = *cont1;
	if(*cont2 > *max && *cont2 > *cont3 && *cont2 > *cont4 && *cont2 > *cont5)
		*max = *cont2;
	else if(*cont3 > *max && *cont3 > *cont4 && *cont3 > *cont5)
		*max = *cont3;
	else if(*cont4 > *max && *cont4 > *cont5)
		*max = *cont4;
	else if(*cont5 > *max)
		*max = *cont5;
	return *max;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa_prodotti(prodotto *prod, const int nn)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < nn; i++) printf("%d. %s\n", prod[i].codice, prod[i].nome);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void acquista_prodotto
(
	prodotto	*prod,
	const int	nn,
	int			*cnt,
	int			*cont1,
	int			*cont2,
	int			*cont3,
	int			*cont4,
	int			*cont5
)
{
	/*~~~~~~~~~~~~~~~~~~*/
	int scelta = 0, xx, i;
	/*~~~~~~~~~~~~~~~~~~*/

	do
	{
		fflush(stdin);
		(*cnt)++;
		printf("Giorno %d\n", *cnt);
		printf("Quale prodotto vuoi acquistare?\n");

		for(i = 0; i < nn; i++)
			printf("COD: %d %s rimanenti in magazzino: %d\n", prod[i].codice, prod[i].nome, prod[i].quantita);

		printf("Inserisci codice corrispondente: ");
		scanf("%d", &xx);
		switch(xx)
		{
		case 11:
			{
				if(prod[0].quantita > 0)
				{
					(*cont1)++;
					prod[0].quantita--;
				}
				else
					printf("quantita esaurita! aquisto non disponibile...\n");
			}
			break;

		case 12:
			{
				if(prod[1].quantita > 0)
				{
					(*cont2)++;
					prod[1].quantita--;
				}
				else
					printf("quantita esaurita! aquisto non disponibile...\n");
			}
			break;

		case 13:
			{
				if(prod[2].quantita > 0)
				{
					(*cont3)++;
					prod[2].quantita--;
				}
				else
					printf("quantita esaurita! aquisto non disponibile...\n");
			}
			break;

		case 14:
			{
				if(prod[3].quantita > 0)
				{
					(*cont4)++;
					prod[3].quantita--;
				}
				else
					printf("quantita esaurita! aquisto non disponibile...\n");
			}
			break;

		case 15:
			{
				if(prod[4].quantita > 0)
				{
					(*cont5)++;
					prod[4].quantita--;
				}
				else
					printf("quantita esaurita! aquisto non disponibile...\n");
			}

		default:
			break;
		}

		printf("vuoi cquistare un altro prodotto? 0 no 1 si\n");
		scanf("%d", &scelta);
		system("cls");
	} while(scelta && *cnt < 10);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_prodotti(prodotto *x, int *nn)
{
	/*~~*/
	int i;
	/*~~*/

	do
	{
		printf("Quanti prodotti vuoi caricare? Max=5\n");
		scanf("%d", nn);
	} while(*nn < 0 || *nn > 5);

	for(i = 0; i < *nn; i++)
	{
		fflush(stdin);
		printf("Inserisci il nome del %d prodotto\n", i + 1);
		gets(x[i].nome);
		printf("Inserisci il prezzo del %d prodotto\n", i + 1);
		scanf("%f", &x[i].prezzo);
		printf("Inserisci la quantita' del %d prodotto\n", i + 1);
		scanf("%d", &x[i].quantita);
		printf("Inserisci Codice (Es. 11,12,13,14,15) del %d prodotto\n", i + 1);
		scanf("%d", &x[i].codice);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	prodotto	x[MAX];
	int			risp, scelta = 0, cont = 0, n = 0, massimo = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Benvenuto nel magazzino! Scegli l'operazione da eseguire :\n");
		printf("1. Carica Prodotti \n");
		printf("2. Acquista \n");
		printf("3. Visualizza Prodotti \n");
		printf("4. Esci \n");
		scanf("%d", &risp);

		switch(risp)
		{
		case 1:		carica_prodotti(x, &n); break;
		case 2:		acquista_prodotto(x, n, &cont, &cont1, &cont2, &cont3, &cont4, &cont5); break;
		case 3:		stampa_prodotti(x, n); break;
		case 4:		break;
		default:	printf("operazione non consentita\n"); break;
		}

		printf("vuoi fare un altra operazione? 0 no 1 si\n");
		scanf("%d", &scelta);
		system("cls");
	} while(risp < 1 || risp > 4 || scelta == 1 && cont < 10);

	if(cont == 10)
	{
		massimo = calcola_massimo(&massimo, &cont1, &cont2, &cont3, &cont4, &cont5);
		if(massimo == cont1)
			printf("prodotto piu venduto in %d giorni e' %s\n", cont, x[0].nome);
		else if(massimo == cont2)
			printf("prodotto piu venduto in %d giorni e' %s\n", cont, x[1].nome);
		else if(massimo == cont3)
			printf("prodotto piu venduto in %d giorni e' %s\n", cont, x[2].nome);
		else if(massimo == cont4)
			printf("prodotto piu venduto in %d giorni e' %s\n", cont, x[3].nome);
		else
			printf("prodotto piu venduto in %d giorni e' %s\n", cont, x[4].nome);
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
