#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Sviluppare una function C che, dato come parametro di input un array di tipo struct struttura { double a;
    float b;
    } e il suo size, restituisca come parametro di output un array composto solo dagli elementi di indice pari.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct struttura
{
	double	a;
	float	b;
} Struttura;
int		dimensione();
void	carica(Struttura *, int);
void	caricapari(Struttura *, Struttura *, int, int *);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void carica(Struttura *vet, int nn)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < nn; i++)
	{
		printf("Inserisci il valore di a \n");
		scanf("%lf", &vet[i].a);
		printf("Inserisci il valore di b \n");
		scanf("%f", &vet[i].b);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void caricapari(Struttura *v1, Struttura *v2, int nn, int *jj)
{
	/*~~*/
	int x;
	/*~~*/

	for(x = 0; x < nn; x += 2)
	{
		v2[*jj].a = v1[x].a;
		v2[*jj].b = v1[x].b;
		(*jj)++;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int dimensione()
{
	/*~~~*/
	int nn;
	/*~~~*/

	do
	{
		printf("Inserisci la dimensione : (MAX=100) \n");
		scanf("%d", &nn);
	} while(nn <= 0 || nn > MAX);
	return nn;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Struttura	vettore[MAX], v2[MAX];
	int			n, j = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	carica(vettore, n);
	caricapari(vettore, v2, n, &j);

	for(int i = 0; i < j; i++) printf("Elemento [%d] %4.1lf %4.2f\n", i + 1, v2[i].a, v2[i].b);

	system("PAUSE");
	return EXIT_SUCCESS;
}
