#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di int e
 * il suo size, determina e restituisce come parametro di output il secondo piu
 * grande elemento dell'array (N.B.: l'array non deve essere ordinato). ;
 * costo al pi� 2n
 */
int		dimensione();
void	carica(int *, int);
int		massimo(int *, int);

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
int massimo(int *vet, int nn)
{
	/*~~~~~~~~~~~~~~~~*/
	int max, max2, temp;
	/*~~~~~~~~~~~~~~~~*/

	/*
	 * calcolo il massimo tra i primi due numeri e li sposto in 2 variabili che
	 * chiamer� MAX e MAX2
	 */
	if(vet[0] > vet[1])
	{
		max = vet[0];
		max2 = vet[1];
	}
	else
	{
		max = vet[1];
		max2 = vet[0];
	}

	/* partendo ora dal 3 elemento scorro la lista e calcolo il 2 massimo */
	for(int i = 2; i < nn; i++)
	{
		if(vet[i] > max)
		{
			temp = max;
			max = vet[i];
			max2 = temp;
		}
		else if(vet[i] > max2)
			max2 = vet[i];
	}

	return max2;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~*/
	int v[MAX], n, m;
	/*~~~~~~~~~~~~~*/

	n = dimensione();
	carica(v, n);
	m = massimo(v, n);
	printf("il secondo elemento piu grande del vettore caricato e' %d\n", m);
	system("PAUSE");
	return EXIT_SUCCESS;
}
