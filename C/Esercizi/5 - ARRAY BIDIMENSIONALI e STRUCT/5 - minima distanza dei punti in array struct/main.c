#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Sviluppare una function C che, dati come parametri di input un array di tipo struct punto fdouble x;
    double y g e il suo size, determina e restituisce come parametri di output gli indici dei due punti che hanno
    distanza minima tra loro.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct punto
{
	double	x;
	double	y;
} Punto;

int		dimensione();
void	carica(Punto *, int);
void	calcola(Punto *, int, float *, int *, int *);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void carica(Punto *vet, int nn)
{
	for(int i = 0; i < nn; i++)
	{
		printf("inserisci l'ordinata del %d punto ", i + 1);
		scanf("%lf", &vet[i].x);
		printf("inserisci l'ascissa del %d punto  ", i + 1);
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
	} while(nn <= 0 || nn > MAX);
	return nn;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void calcola(Punto *vet, int nn, float *minimo, int *indice1, int *indice2)
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
			 * se il risultato delle varie distanze � minore del mio minimo precedente
			 * allora aggiorno il minimo
			 */
			if(risultato < *minimo)
			{
				*minimo = risultato;
				*indice1 = i;
				*indice2 = j;
			}
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Punto	v[MAX];
	int		n, s = 0, k = 1;
	float	ris1 = 0, ris2 = 0, pot1 = 0, pot2 = 0, minim;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	carica(v, n);

	/* calcolo la distanza del primo punto(x,y) dal secondo */
	ris1 = v[s].x - v[k].x;
	ris2 = v[s].y - v[k].y;
	pot1 = pow(ris1, 2);
	pot2 = pow(ris2, 2);

	/* suppongo che sia il minimo che cerco */
	minim = sqrt(pot1 + pot2);

	/* ora chiamo la funzione calcola */
	calcola(v, n, &minim, &s, &k);
	printf
	(
		"il minimo tra le distanze dei punti inseriti e' %f tra il numero di indice %d e il numero di indice %d\n",
		minim,
		s + 1,
		k + 1
	);

	system("PAUSE");
	return EXIT_SUCCESS;
}
