#include <stdlib.h>
#include <stdio.h>
#define max 100

/*
 * Scrivere una funzione che prende in input due array di dimensioni n e m,
 * rispettivamente, e restituisce ;
 * un array composto dalla concatenazione dei due array in modo tale che nelle
 * posizioni dispari ;
 * sono contenuti i valori del primo array e nelle posizioni pari quelle del
 * secondo.
 */
void	carica(int *, int);
void	stampa(int *, int);
void	calcola(int *, int *, int *, int);
int		dimensione();

/*
 =======================================================================================================================
    sottoprogramma dove ricevo la dimensione del vettore
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
	} while(n1 <= 0 || n1 > 100);
	return n1;
}

/*
 =======================================================================================================================
    sottoprogramma di caricamento
 =======================================================================================================================
 */
void carica(int *v, int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf("inserisci il [%d] elemento \n ", i);
		scanf("%d", &v[i]);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void calcola(int *v1, int *v2, int *v3, int n)
{
	for(int i = 0; i < n; i++)
	{
		v3[2 * i + 1] = v1[i];
		v3[2 * i] = v2[i];
	}
}

/*
 =======================================================================================================================
    sottoprogramma di stampa
 =======================================================================================================================
 */
void stampa(int *v, int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++) printf(" Elemento : %d \n ", v[i]);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int v1[max], v2[max], v3[max], n, m, d;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/* chiamate ai sottoprogrammi */
	printf("Primo vettore :\n");
	n = dimensione();		/* sottoprogramma che restituisce la dimensione del 1 vettore */
	printf("Secondo vettore :\n");
	m = dimensione();		/* sottoprogramma che restituisce la dimensione del 2 vettore */
	d = n + m;				/* definisco la dimensione del 3 vettore */
	printf("Carico il primo vettore : \n");
	carica(v1, n);			/* caricamento 1 vettore */
	printf("Carico il secondo vettore \n");
	carica(v2, m);			/* caricamento 2 vettore */
	calcola(v1, v2, v3, d); /* caricamento 3 vettore */
	printf("Vettore ottenuto caricando gli elementi di posizione dispari dal Primo vettore e le pari dal secondo \n");
	stampa(v3, d);			/* stampa 3 vettore */

	system("PAUSE");
	return EXIT_SUCCESS;
}
