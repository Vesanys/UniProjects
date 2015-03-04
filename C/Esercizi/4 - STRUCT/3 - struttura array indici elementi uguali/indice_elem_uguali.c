#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Sviluppare una function C che, dati come parametri di input un array di tipo struct struttura { double a;
    double b;
    double c} e il suo size, determini e restituisca come parametri di output gli indici degli elementi uguali.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct struttura
{
	double	a;
	double	b;
	double	c;
} Struttura;

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Struttura	vettore[MAX];
	int			n, m[MAX][MAX], elem_uguali = 0, j;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/* dimensione */
	do
	{
		printf("inserisci dimensione (max=100) \n");
		scanf("%d", &n);
	} while(n <= 0 || n > MAX);

	/* caricamento */
	for(int i = 0; i < n; i++)
	{
		printf("Elemento %d\n", i + 1);
		printf("inserisci il valore di a \n");
		scanf("%lf", &vettore[i].a);
		printf("inserisci il valore di b \n");
		scanf("%lf", &vettore[i].b);
		printf("inserisci il valore di c \n");
		scanf("%lf", &vettore[i].c);
	}

	for(int j = 0; j < n; j++)
	{
		for(int k = j + 1; k < n; k++)
		{
			if(vettore[j].a == vettore[k].a && vettore[j].b == vettore[k].b && vettore[j].c == vettore[k].c)
			{
				elem_uguali = 1;
				m[j][k - 1] = j;
				m[j][k] = k;
			}
		}
	}

	if(elem_uguali)
	{
		printf("elementi uguali presenti nell array!! \n");
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				printf("%d %d", m[i][j], m[i][j + 1]);
			}
		}
	}
	else
		printf("Non sono presenti elementi uguali nell array di struttura caricato! \n");

	system("PAUSE");
	return EXIT_SUCCESS;
}
