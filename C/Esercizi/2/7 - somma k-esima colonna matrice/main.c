#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array 2D di int,
 * il numero delle righe, il numero delle colonne e un int k, determina e
 * restituisce come parametro di output la somma degli elementi della k-sima
 * colonna.
 */
void	carica(int[][MAX], int, int);	/* prototipo del sottoprogramma di caricamento */
void	dimensione(int *, int *);		/* protoripo del sottoprogramma dove ricevo la dimensione dell'array
										 * multidimensionale con parametri passati x riferimento */
int		calcola(int[][MAX], int, int);

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
		printf("Quante righe avra' la Matrice? MAX 100\n");
		scanf("%d", n);
		printf("Quante colonne avra' la Matrice? MAX 100\n");
		scanf("%d", m);
	} while(*n < 0 || *m < 0 || *n > MAX || *m > MAX);
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
int calcola(int mm[][MAX], int n, int k)
{
	/*~~~~~~~~~~~~~~*/
	int risultato = 0;
	/*~~~~~~~~~~~~~~*/

	for(int j = 0; j < n; j++) risultato += mm[j][k];

	return risultato;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int n, m, mat[MAX][MAX], ris, k;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&n, &m);
	carica(mat, n, m);
	do
	{
		printf("inserisci K (K<%d): \n", m);
		scanf("%d", &k);
	} while(k < 0 || k > m);
	ris = calcola(mat, n, k);

	printf("la somma degli elementi della k-esima colonna e': %d\n", ris);

	system("PAUSE");
	return EXIT_SUCCESS;
}
