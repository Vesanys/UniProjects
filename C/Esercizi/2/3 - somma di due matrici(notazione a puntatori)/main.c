#include <stdio.h>
#include <stdlib.h>
#define MAX 20	/* define per la dimensione massima */

/*
 * Esercizio 3 Scrivere una funzione che prende in input due matrici e restituisce
 * come output una matrice ;
 * che corrisponde alla somma delle due matrici. Usare la notazione a puntatori.
 */
void	carica(int *, const int, const int);	/* prototipo del sottoprogramma di caricamento */
void	dimensione(int *, int *);	/* protoripo del sottoprogramma dove ricevo la dimensione dell'array
									 * multidimensionale con parametri passati x riferimento */
void	calcola(int[][MAX], int[][MAX], int[][MAX], const int, const int);
void	stampa(int[][MAX], const int, const int);	/* prototipo di stampa della matrice */

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void calcola(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], const int n, const int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) mat3[i][j] = mat1[i][j] + mat2[i][j];
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void dimensione(int *n, int *m)
{

	/*
	 * prendo da input la dimensione delle righe e delle colonne assicurandomi che
	 * siano compresi tra 0 e la dimensione massima consentita
	 */
	do
	{
		printf("Quante righe avranno le Matrici? MAX 20\n");
		scanf("%d", n);
		printf("Quante colonne avranno le Matrici? MAX 20\n");
		scanf("%d", m);
	} while(*n < 0 || *m < 0 || *n > MAX || *m > MAX);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(int *mm, const int n, const int m)
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
			scanf("%d", (mm + i * MAX + j));
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
		for(int j = 0; j < m; j++) printf("Matrice inserita : [%d][%d] %d\n ", i, j, matrice[i][j]);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int mat1[MAX][MAX], mat2[MAX][MAX], mat3[MAX][MAX], n, m;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&n, &m);
	printf("Carico la prima Matrice:\n");
	carica(&mat1[0][0], n, m);
	printf("Carico la seconda Matrice:\n");
	carica(&mat2[0][0], n, m);
	calcola(mat1, mat2, mat3, n, m);
	stampa(mat3, n, m);

	system("pause");

	return 0;
}
