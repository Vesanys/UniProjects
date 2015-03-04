#include <stdio.h>
#include <stdlib.h>

/*
 * Scrivere una funzione che prende in input la dimensione di una matrice e
 * restituisce in output il puntatore alla matrice allocata dinamicamente.
 */
int		**allocaMatrice(int righe, int colonne);
void	dimensione(int *, int *);
void	carica(int **, const int, const int);
void	stampa(int **, const int, const int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~*/
	int **mat;
	int i, j, righe, colonne;
	/*~~~~~~~~~~~~~~~~~~~~~*/

	dimensione(&righe, &colonne);
	mat = allocaMatrice(righe, colonne);
	carica(mat, righe, colonne);
	stampa(mat, righe, colonne);

	/* dealloco matrice */
	for(i = 0; i < righe; i++)
	{
		free(mat[i]);
	}

	free(mat);

	system("pause");

	return 0;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(int **mm, const int n, const int m)
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
void dimensione(int *n, int *m)
{

	/*
	 * prendo da input la dimensione delle righe e delle colonne assicurandomi che
	 * siano positive
	 */
	do
	{
		printf("Quante righe avranno le Matrici? \n");
		scanf("%d", n);
		printf("Quante colonne avranno le Matrici? \n");
		scanf("%d", m);
	} while(*n < 0 || *m < 0);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa(int **matrice, const int n, const int m)
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
int **allocaMatrice(int righe, int colonne)
{
	/*~~~~~~*/
	int i;
	int **mat;
	/*~~~~~~*/

	/* funzione per l allocazione dinamica per le righe */
	mat = (int **) malloc(righe * sizeof(int *));
	if(mat == NULL)
	{
		puts("Spazio insufficiente");
		exit(0);
	}

	for(i = 0; i < righe; i++)
	{
		mat[i] = (int *) malloc(colonne * sizeof(int));
		if(mat[i] == NULL)
		{
			puts("Spazio insufficiente");
			exit(0);
		}
	}

	return mat;
}
