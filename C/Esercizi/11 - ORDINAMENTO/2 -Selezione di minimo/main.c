#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una procedura che dato in input un array di strutture, ordini l'array in base al prezzo usando un
    algoritmo di ordinamento per selezione di minimo. La struttura e struct prodotto 
    {char *nome;
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
void	scambia(Prodotto *, Prodotto *);
void	minimo(Prodotto *, int, double *, int *);

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
    function di ordinamento per selezione di minimo
 =======================================================================================================================
 */
void ordina(Prodotto *prod, const int n)
{
	/*~~~~~~~~~~~~~~~~~~*/
	int		i, indice_min;
	double	min;
	/*~~~~~~~~~~~~~~~~~~*/

	for(i = 0; i < n - 1; i++)
	{
		minimo(&prod[i], n - i, &min, &indice_min);
		scambia(&prod[i], &prod[indice_min + i]);// spiazamento dell indice
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void minimo(Prodotto *prod, int n, double *min, int *indice_min)
{
	/*~~*/
	int i;
	/*~~*/

	*min = prod[0].prezzo;
	*indice_min = 0;

	for(i = 0; i < n; i++)
	{
		if(prod[i].prezzo < *min)
		{
			*min = prod[i].prezzo;
			*indice_min = i;
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void scambia(Prodotto *v1, Prodotto *v2)
{
	/*~~~~~~~~~*/
	Prodotto	temp[1];
	
	/*~~~~~~~~~*/

	*temp = *v1;
	*v1 = *v2;
	*v2= *temp;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_prodotti(Prodotto *prod, const int nn)
{
	fflush(stdin);
	for(int i = 0; i < nn; i++)
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
	int			n, uguali = 0;
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
