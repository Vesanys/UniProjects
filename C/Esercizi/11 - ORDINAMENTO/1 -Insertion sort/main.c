
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una procedura che dato in input un array di strutture, ordini l'array in base al prezzo usando un
    algoritmo di ordinamento per inserimento. La struttura e struct prodotto {char *nome;
    int codice;
    double prezzo;
    };
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct prodotto
{
	char	*nome;
	int		codice;
	double	prezzo;
} Prodotto;
int		dimensione();
void	carica_prodotti(Prodotto *, const int);
void	ordina(Prodotto *, const int);
void	stampa(Prodotto *, const int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int dimensione()
{
	/*~~*/
	int n;
	/*~~*/

	do
	{
		printf("Quanti prodotti vuoi caricare? \n");
		scanf("%d", &n);
	} while(n < 0 || n > MAX);

	return n;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa(Prodotto *prod, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++) printf(" Prodotto %d : %2.2lf\n", i + 1, prod[i].prezzo);
}

/*
 =======================================================================================================================
    function di ordinamento per inserimento
 =======================================================================================================================
 */
void ordina(Prodotto *prod, const int n)
{
	/*~~~~~~~~~~~~~~*/
	int		i, j;
	double	el_da_ins;
	/*~~~~~~~~~~~~~~*/

	for(i = 1; i < n; i++)
	{
		el_da_ins = prod[i].prezzo;
		j = i - 1;
		while(j >= 0 && el_da_ins < prod[j].prezzo)
		{
			prod[j + 1].prezzo = prod[j].prezzo;
			j--;
		}

		prod[j + 1].prezzo = el_da_ins;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_prodotti(Prodotto *prod, const int nn)
{
     int i;
	fflush(stdin);
	for(i = 0; i < nn; i++)
	{
		printf("Nome %d prodotto : ", i + 1);
		scanf("%s", &prod[i].nome);
		printf("Codice %d prodotto : ", i + 1);
		scanf("%d", &prod[i].codice);
		printf("Prezzo %d prodotto : ", i + 1);
		scanf("%lf", &prod[i].prezzo);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	Prodotto	prod[MAX];
	int			n;
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	if(n == 0)
		printf("E' stato scelto di non inserire nessun elemento\n");
	else
	{
		carica_prodotti(prod, n);
		ordina(prod, n);
		printf(" Struttura ordinata in base al prezzo :\n");
		stampa(prod, n);
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
