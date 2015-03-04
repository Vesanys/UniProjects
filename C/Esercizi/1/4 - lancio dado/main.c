#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/*
 =======================================================================================================================
    Due giocatori si sfidano lanciando un "dado truccato". Il dado ha dei valori interi nell'in- tervallo [5;
    15]. A ogni turno vince il giocatore che ottiene un punteggio maggiore. In caso di parit� il punto viene
    assegnato a entrambi. Simulare 10 sfide e visualizzare il giocatore che vince pi� volte.
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		i, posizione_iniziale, nuova_posizione;
	char	griglia[10][10] =
	{
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	}

	srand(time(NULL));
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	ncr = 0 + rand() % (9 + 1 - 0);
	ncc = 0 + rand() % (9 + 1 - 0);
	griglia[ncr][ncc] = 'X';

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf(" %c", griglia[i][j]);
			printf("\n");
		}
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
