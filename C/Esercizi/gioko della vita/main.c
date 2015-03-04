#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/* Gioco della VITA*/
void	stampa_griglia(char[][15]);


/*
 =======================================================================================================================
    Algoritmo del Gioco della Vita (Game of Life). Il Gioco della Vita consiste in una
scacchiera in cui ogni casella rappresenta una cellula, che può essere viva o
morta. Ogni cellula ha, in generale, quattro cellule vicine (a meno che la cellula
non si trovi sul bordo della scacchiera). L’algoritmo usa un array 2D nxn, con
n=45, per simulare la scacchiera. L’algoritmo esamina n volte la scacchiera.
Durante ogni passo aggiorna lo stato di tutte le cellule sulla scacchiera nel
seguente modo: se una cellula ha uno, due o tre cellule vicine vive allora la
cellula deve essere posta nello stato “viva”; altrimenti deve essere posta nello
stato “morta” (si noti che questa regola consente a una cellula morta di diventare
viva). Dopo l’ultimo passo, l’algoritmo visualizza l’array 2D aggiornato. Ogni
cellula viva è visualizzata con un asterisco; ogni cellula morta con uno spazio.
Fare attenzione al fatto che la scacchiera deve essere aggiornata solo alla fine di
ogni passo: ciò significa che l’algoritmo deve usare un array per memorizzare la
scacchiera attuale e un array per memorizzare la scacchiera modificata. Usare le
tre seguenti configurazioni iniziali(per i tre test): solo la cellula centrale è viva,
ovvero quella di indice 22,22; solo le cellule 22,22 e 22,23 sono vive; solo le
cellule 0,0 44,44 e 44,43 sono vive.
 =======================================================================================================================
 */
void stampa_griglia(char griglia[][10])
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf(" %c", griglia[i][j]);
			printf(",");
		}

		printf("\n");
	}
}


/*
 =======================================================================================================================
 MAIN
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		i, ncr, ncc, j;
	char	griglia[10][10] =
	{{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		
		
	};
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	srand(time(NULL));
// genera la posizione iniziale random della prima cellula viva

	ncr = rand() % 10;
	ncc = rand() % 10;


    griglia[ncr][ncc] = '*';
	stampa_griglia(griglia);

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
              if(griglia[ncr][ncc]
              }
              }


	system("PAUSE");
	return EXIT_SUCCESS;
}
