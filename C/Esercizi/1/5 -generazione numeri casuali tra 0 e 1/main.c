#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

/*
 * Scrivere una procedura che dato una ascissa x calcoli la seguente funzione
 * matematica (x3 + 3x + 5)/(8x + 1) Scrivere successivamente un programma che
 * calcoli e visualizzi il risultato della funzione in 20 ascisse casuali scelte
 * nell'intervallo [0;
 * 1].
 */
double	calcola(double);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
double calcola(double x)
{
	/*~~~~~~*/
	double	f;
	/*~~~~~~*/

	f = ((pow(x, 3) + (3 * x) + 5)) / ((8 * x) + 1);
	return f;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~*/
	int		i;
	double	xc, risultato, x;
	/*~~~~~~~~~~~~~~~~~~~~~*/

	printf("inserisci il valore di X:\n");
	scanf("%lf", &x);
	risultato = calcola(x);
	printf("funzione : %lf \n", risultato);

	printf("Generazione ascisse casuali\n");
	srand(time(NULL));
	for(i = 0; i < 20; i++)
	{
		xc = (double) (rand()) / ((double) RAND_MAX);
		printf("ascissa x scelta %1.2lf \n", xc);
		risultato = calcola(xc);
		printf("funzione : %1.3lf \n", risultato);
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
