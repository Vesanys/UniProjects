#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array 2D di int,
 * il numero delle righe e il numero delle colonne, determina e restituisce come
 * parametro di output il massimo tra le somme degli elementi di ogni riga
 */
void	carica(int[][MAX], int, int);			/* prototipo del sottoprogramma di caricamento */
void	dimensione(int *, int *);				/* protoripo del sottoprogramma dove ricevo la dimensione dell'array
												 * multidimensionale con parametri passati x riferimento */
void	calcola(int[][MAX], int, int, int *);
void	ricerca_max(int *, int, int *, int *);	/* prototipo di ricerca */

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void ricerca_max(int *v1, int nn, int *massimo, int *pos)
{
	for(int i = 0; i < nn; i++)
	{
		if(v1[i] > *massimo)
		{
			*massimo = v1[i];
			*pos = i;
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void dimensione(int *n, int *m)
{

	/*
	 * prendo da input la dimensione delle righe e delle colonne assicurandomi che
	 * siano maggiori di 0
	 */
	do
	{
		printf("Quante righe avra' la Matrice?\n");
		scanf("%d", n);
		printf("Quante colonne avra' la Matrice?\n");
		scanf("%d", m);
	} while(*n < 0 || *m < 0 || *m > MAX || *n > MAX);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(int mm[][MAX], int n, int m)
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	/* carico la matrice */
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("Inserisci l'elemento n. [%d][%d] ", i, j);
			scanf("%d", &mm[i][j]);
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void calcola(int mm[][MAX], int n, int m, int *v)
{
	/*~~~~~~~~~~*/
	int somma = 0;
	/*~~~~~~~~~~*/

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			somma += mm[i][j];
			v[i] = somma;
		}

		somma = 0;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int n, m, mat[MAX][MAX], vet[MAX], massimo = 0, posiz;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&n, &m);
	carica(mat, n, m);
	printf("\n");
	calcola(mat, n, m, vet);

	for(int i = 0; i < n; i++) printf("\nsomma degli elementi di riga %d [%d] \n", i, vet[i]);
	ricerca_max(vet, n, &massimo, &posiz);

	printf("\nil massimo tra le somme degli elementi di ogni riga e' %d \n", massimo);

	system("PAUSE");
	return EXIT_SUCCESS;
}
