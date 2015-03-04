#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una funzione che dato in input due array di strutture del seguente tipo struct prodotto {char *nome;
    int codice;
    double prezzo;
    };
    verifichi se gli array di struct sono uguali e in caso affermativo restituisca l'indice del prezzo piu basso.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct prodotto
{
	char	nome[20];
	int		codice;
	double	prezzo;
} Prodotto;
void	carica_prodotti(Prodotto *, const int);
int		uguaglianza(Prodotto *, Prodotto *, const int);
void	minimo(Prodotto *, const int, int *, double *);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void minimo(Prodotto *v1, const int nn, int *pos, double *min)
{
	/*~~~~~~~~~*/
	int i = 0, j;
	/*~~~~~~~~~*/

	*min = v1[i].prezzo;

	for(j = 0; j < nn; j++)
	{
		if(v1[j].prezzo < *min)
		{
			*min = v1[j].prezzo;
			*pos = j;
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int uguaglianza(Prodotto *v1, Prodotto *v2, const int nn)
{
	/*~~~~~~~~~~~~~*/
	int u = 1, i = 0;
	/*~~~~~~~~~~~~~*/

	while(i < nn && u)
	{

		/*
		 * controllo se i codici dei prodotti dei due array sono uguali e se anche i nomi
		 * lo sono ;
		 * la funz strcmp confronta le stringhe e ritorna 0 se sono uguali appena incontra
		 * un elemento diverso esce
		 */
		if(v1[i].codice != v2[i].codice || strcmp(v1[i].nome, v2[i].nome) != 0) u = 0;
		i++;
	}

	return u;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_prodotti(Prodotto *prod1, const int nn)
{
	/*~~*/
	int i;
	/*~~*/

	fflush(stdin);
	for(i = 0; i < nn; i++)
	{
		printf("Nome %d prodotto : ", i + 1);
		scanf("%s", &prod1[i].nome);

		printf("Codice %d prodotto Es. 11,12,13...1n : ", i + 1);
		scanf("%d", &prod1[i].codice);

		printf("Prezzo %d prodotto : ", i + 1);
		scanf("%lf", &prod1[i].prezzo);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Prodotto	v1[MAX], v2[MAX];
	int			n, uguali = 0, posiz1 = 0, posiz2 = 0;
	double		minim1 = 0, minim2 = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Quanti prodotti vuoi caricare? \n");
		scanf("%d", &n);
	} while(n < 0 || n > MAX);
	printf("Carico Primo array : \n");
	carica_prodotti(v1, n);
	printf("Carico Secondo array : \n");
	carica_prodotti(v2, n);

	uguali = uguaglianza(v1, v2, n);

	/* controllo se effettivamente gli array di struct caricati sono uguali */
	if(uguali)
	{
		printf("Array di prodotti uguali \n");

		/*
		 * ora confermato questo chiamo la funzione per il minimo e mi faccio restituire
		 * la posizione
		 */
		minimo(v1, n, &posiz1, &minim1);

		/* lo stesso anche per il secondo vettore */
		minimo(v2, n, &posiz2, &minim2);

		/* ora controllo quale tra i due prezzi piu bassi � il minore e lo stampo */
		if(minim1 < minim2)
		{
			printf
			(
				"Il prezzo piu basso negli array caricati e : %lf che corrisponde al prodotto di posizione : %d del primo array",
				minim1,
				posiz1
			);
		}
		else
		{
			printf
			(
				"Il prezzo piu basso negli array caricati e : %lf che corrisponde al prodotto di posizione : %d del secondo array",
				minim2,
				posiz2
			);
		}
	}
	else
		printf("Array diversi\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}
