#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Sviluppare una function C che, dato come parametro di input un array di tipo struct punto { double x;
    double y } e il suo size, determina e restituisce come parametro di output la massima distanza tra i punti.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct punto
{
	double	x;
	double	y;
} Punto;

int		dimensione();
void	carica(Punto *, int);
float	calcola(Punto *, int, float);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void carica(Punto *vet, int nn)
{
	for(int i = 0; i < nn; i++)
	{
		printf("inserisci l'ordinata del %d punto \n", i + 1);
		scanf("%lf", &vet[i].x);
		printf("inserisci l'ascissa del %d punto \n", i + 1);
		scanf("%lf", &vet[i].y);
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
		printf("Quanti punti vuoi inserire? (max=100) \n");
		scanf("%d", &nn);
	} while(nn <= 0 || nn > 100);
	return nn;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
float calcola(Punto *vet, int nn, float massimo)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	float	risult1 = 0, risult2 = 0, poten1 = 0, poten2 = 0, risultato = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	for(int i = 0; i < nn; i++)
	{
		for(int j = i + 1; j < nn; j++)
		{
			risult1 = vet[i].x - vet[j].x;
			risult2 = vet[i].y - vet[j].y;
			poten1 = pow(risult1, 2);
			poten2 = pow(risult2, 2);
			risultato = sqrt(poten1 + poten2);

			/*
			 * se il risultato delle varie distanze � maggiore del mio massimo precedente
			 * allora aggiorno il massim
			 */
			if(risultato > massimo) massimo = risultato;
		}
	}

	return massimo;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Punto	v[MAX];
	int		n, s = 0, k = 0;
	float	ris1 = 0, ris2 = 0, pot1 = 0, pot2 = 0, maxim = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	carica(v, n);

	/* calcolo la distanza del primo punto(x,y) dal secondo */
	ris1 = v[s].x - v[k + 1].x;
	ris2 = v[s].y - v[k + 1].y;
	pot1 = pow(ris1, 2);
	pot2 = pow(ris2, 2);

	/* suppongo che sia il massimo che cerco */
	maxim = sqrt(pot1 + pot2);

	/* ora chiamo la funzione calcola */
	maxim = calcola(v, n, maxim);
	printf("il massimo tra le distanzze dei punti inseriti e' %f\n", maxim);

	system("PAUSE");
	return EXIT_SUCCESS;
}
