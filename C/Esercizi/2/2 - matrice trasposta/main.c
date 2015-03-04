#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Scrivere una funzione che prende in input una matrice e restituisca in output
 * la matrice trasposta (ovvero la matrice in cui la j-esima colonna e la j-esima
 * riga della matrice data, per j = 1, 2, ..... n).
 */
void	dimensione(int *, int *);
void	carica(int[][MAX], int, int);
void	carica_trasposta(int[][MAX], int[][MAX], int, int);
void	stampa(int[][MAX], int, int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void dimensione(int *n, int *m)
{
	do
	{
		printf("Quante righe avra' la matrice? MAX = 100\n");
		scanf("%d", n);
		printf("Quante colonne avra' la matrice? MAX = 100\n");
		scanf("%d", m);
	} while(*n < 0 || *m < 0 || *n > MAX || *m > MAX);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(int mat[][MAX], int n, int m)
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
			scanf("%d", &mat[i][j]);
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_trasposta(int mat[][MAX], int mtra[][MAX], int n, int m)
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	/* carico la matrice */
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			mtra[i][j] = mat[j][i];
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa(int matrice[][MAX], int n, int m)
{

	/* ciclo di stampa */
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) printf("[%d][%d] %d\n", i, j, matrice[i][j]);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int m1[MAX][MAX], mt[MAX][MAX], n, m;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&n, &m);
	carica(m1, n, m);
	carica_trasposta(m1, mt, n, m);
	printf("matrice inserita:\n");
	stampa(m1, n, m);
	printf("matrice trasposta: \n");
	stampa(mt, n, m);
	system("PAUSE");
	return EXIT_SUCCESS;
}
