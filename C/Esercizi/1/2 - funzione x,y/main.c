#include <stdlib.h>
#include <stdio.h>

/*
 =======================================================================================================================
    Scrivere una procedura che dati due valori x e y calcoli i valori delle seguenti funzioni matematiche (x3 + 3x +
    5)/(8x + 1) (y4)/(1 + y) Scrivere successivamente un programma che calcoli e visualizzi il risultato delle funzioni
    precedenti nei punti (0; 0), (1; 1), (3; 3), (5; 5), ...., (9; 9).
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		x = 0, xxx, y = 0, yyyy;
	float	fx, fy;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		xxx = x * x * x;
		yyyy = y * y * y * y;
		fx = ((xxx + (3 * x) + 5) / ((8 * x) + 1));
		fy = yyyy / (1 + y);
		printf("il risultato dela funzione X con x=%d e': %2.2f\n", x, fx);
		printf("il risultato dela funzione Y con y=%d e': %2.2f\n", y, fy);
		x++;
		y++;
	} while(x < 10 && y < 10);
	system("PAUSE");
	return EXIT_SUCCESS;
}
