#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di int, il
 * suo size e un int k, determina e restituisce come parametro di output il k-imo
 * piu grande elemento dell'array (N.B.: l'array non deve essere ordinato). ;
 * costo =n*k con k<n, n^2 con k=
 */
int		dimensione();
void	carica(int *, int);
void	massimo(int *, int *, const int);
void	shift(int *, int, int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int dimensione()
{
	/*~~~*/
	int n1;
	/*~~~*/

	do
	{
		printf("inserisi dimensione : \n");
		scanf("%d", &n1);
	} while(n1 <= 0 || n1 > MAX);
	return n1;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(int *v, int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf("inserisci il [%d] elemento \n ", i + 1);
		scanf("%d", &v[i]);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void massimo(int *vet, int *pos, const int nn, int *max)
{
	/*~~~~~*/
	int temp;
	/*~~~~~*/

	*max = vet[0];

	for(int i = 1; i <= nn; i++)
	{
		if(vet[i] > *max)
		{
			*max = vet[i];
			*pos = i;
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void shift(int *vet, int nn, int pos)
{
	/*~~~~~~~~*/
	int i, temp;
	/*~~~~~~~~*/

	for(i = pos; i <= nn; i++)
	{
		temp = vet[i];
		vet[i] = vet[i + 1];
		vet[i + 1] = temp;
	}

	for(i = 0; i < nn; i++) printf("%d\n", vet[i]);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int v[MAX], n, m, posiz, k, i = 0, massim;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	carica(v, n);
	do
	{
		printf("inserisci k\n");
		scanf("%d", &k);
	} while(k < 0 || k > n);

	do
	{
		massimo(v, &posiz, n - i, &massim);
		shift(v, n, posiz);
		i++;
	} while(i < k);

	system("PAUSE");
	return EXIT_SUCCESS;
}
