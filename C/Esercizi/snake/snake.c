#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/* Robottino */
void	stampa_griglia(char[][15]);
void	calcola_max(int[], int *);
void	pulisci(int[]);

/*
 =======================================================================================================================
    Algoritmo per la simulazione del movimento di un robot in una stanza. La stanza è pavimentata a tasselli quadrati
    (caselle) ed è dotata di pareti esterne e interne come in figura. Il robot si muove sempre solo di una casella
    alla volta, scelta tra una delle quattro caselle vicine. Il robot è in grado di "vedere", cioè di
    stabilire, guardando in una delle quattro direzioni (avanti, indietro, sinistra, destra), quante sono le caselle
    libere (in linea retta) fino alla parete. La legge con cui il robot si muove è la seguente: nel 20% dei casi il
    robot si muove a caso in una delle quattro caselle vicine possibili (parete permettendo);
    nell'80% dei casi il robot prima "vede" e individua la direzione (avanti, indietro, sinistra, destra) del
    movimento (scegliendo quella cui corrisponde il percorso possibile più lungo;
    nel caso di più percorsi di massima lunghezza, la direzione viene scelta a caso tra questi) e poi si muove
    (sempre di un solo passo) in quella direzione. La simulazione termina quando il robot "esce dalla porta" della
    stanza (in basso a sinistra nella figura). L'algoritmo deve visualizzare il percorso del robot dopo ogni passo,
    mostrando la stanza e la posizione del robot (comprimere le figure in modo da non aumentare a dismisura il numero
    di pagine della Relazione).
 =======================================================================================================================
 */
void stampa_griglia(char griglia[][15])
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			printf(" %c", griglia[i][j]);
			printf(",");
		}

		printf("\n");
	}
}

/*
 =======================================================================================================================
 ALGORITMO PER IL CALCOLO DEL MASSIMO                                                                                                                                                                                                                                            
 =======================================================================================================================
 */
void calcola_max(int v[], int *pos)
{
	/*~~~~~~~*/
	int i, max;
	/*~~~~~~~*/

	max = v[0];
	for(i = 1; i < 3; i++)
		if(v[i] > max)
		{
			max = v[i];
			*pos = i;
		}
}

/*
 =======================================================================================================================
 PULIZIA VETTORE
 =======================================================================================================================
 */
void pulisci(int v[])
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < 3; i++) v[i] = 0;
}

/*
 =======================================================================================================================
 MAIN
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		i, posizione_iniziale, nuova_posizione, ncr, ncc, j, risp = 0, movimento, v[3], pos;
	char	griglia[15][15] =
	{
		{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
		{ 'U', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'U', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'U', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
		{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	srand(time(NULL));
// controllo che la posizione iniziale random generata dal pc non capiti su una parete
do{
	ncr = rand() % 10;
	ncc = rand() % 10;
}while(griglia[ncr][ncc]!=' ');

    griglia[ncr][ncc] = 'S';
	stampa_griglia(griglia);

	/* generare il movimento del robot */
	do
	{
		nuova_posizione = 0 + rand() % 100;
	//	printf("Nuova posizione del robottino %d \n", nuova_posizione);
		if(nuova_posizione >= 0 && nuova_posizione <= 20)
		{
			movimento = 0 + rand() % 20;
			if(movimento > 0 && movimento <= 5)
			{
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncr = ncr - 1;	/* sposto il robottino a NORD di una casella */
				griglia[ncr][ncc] = 'S';
				stampa_griglia(griglia);
				system("pause");
			}
			else if(movimento >= 6 && movimento <= 10)
			{
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncr = ncr + 1;	/* sposto il robottino a SUD di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
					system("pause");
			}
			else if(movimento >= 11 && movimento <= 15)
			{
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncc = ncc - 1;	/* sposto il robottino a OVEST di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
				system("pause");
				system("cls");
			}
			else
			{
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncc = ncc + 1;	/* sposto il robottino a EST di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
					system("pause");
			}
		}

		/* il robottino prima "vede" la direzione da prendere e poi la prende */
		else if(movimento >= 21 && movimento <= 100)
		{
			pulisci(v);
			do
			{
				ncr = ncr - 1;
				v[0]++;
			} while(griglia[ncr][ncc] == ' ');
			do
			{
				ncr = ncr + 1;
				v[1]++;
			} while(griglia[ncr][ncc] == ' ');
			do
			{
				ncc = ncc - 1;
				v[2]++;
			} while(griglia[ncr][ncc] == ' ');
			do
			{
				ncc = ncc + 1;
				v[3]++;
			} while(griglia[ncr][ncc] == ' ');
		

		/* calcolo massimo */
		calcola_max(v, &pos);
		switch(pos)
		{
		case 0:
			{
				printf("il robottino sceglie di andare a NORD\n");
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncr = ncr - 1;	/* sposto il robottino a NORD di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
			}
			break;

		case 1:
			{
				printf("il robottino sceglie di andare a SUD\n");
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncr = ncr + 1;	/* sposto il robottino a SUD di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
			}
			break;

		case 2:
			{
				printf("il robottino sceglie di andare a OVEST\n");
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncc = ncc - 1;	/* sposto il robottino a OVEST di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
			}
			break;

		case 3:
			{
				printf("il robottino sceglie di andare a EST\n");
				griglia[ncr][ncc] = ' ';	/* pulisco la posizione precedente */
				ncc = ncc + 1;	/* sposto il robottino a EST di una casella */
				griglia[ncr][ncc] = 'S';
					stampa_griglia(griglia);
			}
			break;
		};
}
		printf("Vuoi far muovere ulteriormente il robottino? 1 SI 0 NO \n");
		scanf("%d", &risp);
	} while(risp==1);

	system("PAUSE");
	return EXIT_SUCCESS;
}
