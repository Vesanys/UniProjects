#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una funzione che calcoli con un approccio divide-et-impera ricorsivo la somma dei prezzi di 10 prodotti
    identicati dalla seguente struttura struct prodotto {int *id;
    char *nome;
    int prezzo;
    };
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct prodotto
{
	int		*id;
	char	*nome;
	int		prezzo;
} Prodotto;
void	carica_prodotti(Prodotto *, const int);
int		somma_ricorsiva_DeI(Prodotto *, const int);

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

		/* do{ */
		printf("Id %d prodotto Es. 11,12,13...1n : ", i + 1);
		scanf("%d", &prod[i].id);

		/*
		 * }while(*prod[i].id<11 || *prod[i].id>(10+nn));
		 */
		printf("Prezzo %d prodotto : ", i + 1);
		scanf("%d", &prod[i].prezzo);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int somma_ricorsiva_DeI(Prodotto *prod, const int nn)
{
	/*~~~~~~~~~~~~~~~~~~~*/
	int mediano, somma = 0;
	/*~~~~~~~~~~~~~~~~~~~*/

	somma += prod[mediano].prezzo;

	/* soluzione del caso base */
	if(nn == 1)
		return prod[0].prezzo;
	else	/* autoattivazioni */
	{
		mediano = (nn - 1) / 2;
		return somma += somma_ricorsiva_DeI(prod, mediano + 1);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int			n = 2, totale = 0;
	Prodotto	p[MAX];
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	printf("Somma ricorsiva DIVIDE ET IMPERA del prezzo di 10 prodotti\n ");
	carica_prodotti(p, n);
	totale = somma_ricorsiva_DeI(p, n - 1);

	printf("la somma dei prezzi di 10 prodotti e' : %d", totale);

	system("PAUSE");
	return EXIT_SUCCESS;
}
