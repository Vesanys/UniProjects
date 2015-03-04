#include <stdlib.h>
#include <stdio.h>

/*
 =======================================================================================================================
    Scrivere una funzione che calcoli la seguente formula (x3 + 3x + 5)/(8x + 1) Scrivere successivamente un programma
    che calcoli i valori della funzione per x = 0, 2,4, 6, .....20.
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~*/
	int		x = 0, xxx;
	float	f;
	/*~~~~~~~~~~~~~~~*/

	do
	{
		xxx = x * x * x;
		f = ((xxx + (3 * x) + 5) / ((8 * x) + 1));
		printf("il risultato dela funzione con x=%d e': %2.2f\n", x, f);
		x += 2;
	} while(x <= 20);
	system("PAUSE");
	return EXIT_SUCCESS;
}
