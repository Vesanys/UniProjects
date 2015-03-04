#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array 2D di oat,
 * il numero delle righe, il numero delle colonne, un int p e un int q (con int p
 * minore di int q), determina e restituisce come parametro di output la somma
 * degli elementi che hanno gli indici di riga e di colonna compresi tra int p e
 * int q.
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
	} while(*n < 0 || *n > MAX || *m < 0 || *m > MAX);
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
int calcola(int matrice[][MAX], int pp, int qq)
{
	/*~~~~~~~~~~*/
	int somma = 0;
	/*~~~~~~~~~~*/

	for(int i = 0; i < qq; i++)
		for(int j = 0; j < qq; j++) somma += matrice[i][j];

	return somma;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int n, m, mat[MAX][MAX], p, q, ris;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&n, &m);
	carica(mat, n, m);

	do
	{
		printf("Inserisci parametri p e q con p<q e compreso tra %d e %d : ", n, m);
		scanf("%d %d", &p, &q);
	} while(p < 0 || q < 0 || p >= q || p > n || p > m || q > n || q > m);

	ris = calcola(mat, p, q);
	printf("la somma degli elementi di indici compresi tra p e q e' %d\n", ris);

	system("PAUSE");
	return EXIT_SUCCESS;
}
