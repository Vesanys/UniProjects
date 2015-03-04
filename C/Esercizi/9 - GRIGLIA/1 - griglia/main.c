#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100

/*
 * Scrivere un programma che calcoli i valori di sin(x) con x denito
 * nell'intervallo [0;
 * 2] e passo di campionamento 0:1.
 */
void	campiona(float funzione (float), float, float, int, float *);
float	funzione(float);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	const float pi = 3.1415926F;
	float		b = 2 * pi, v[MAX], x;
	int			n, i, a = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("quanti punti vuoi calcolare?\n");
		scanf("%d", &n);
	} while(n < 0);
	campiona(funzione, a, b, n, v);

	for(i = 0; i < n; i++) printf(" %2.3f\n", v[i]);
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void campiona(float funzione (float), float a, float b, int n, float *v)
{
	/*~~~~~~~~~~~~~~~~~~~~~*/
	float	passo, p_griglia;
	/*~~~~~~~~~~~~~~~~~~~~~*/

	passo = 0.1;
	p_griglia = a;

	for(int i = 0; i < n; i++)
	{
		v[i] = funzione(p_griglia);
		p_griglia = a + (i + 1) * passo;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
float funzione(float x)
{
	return sin(x);
}
