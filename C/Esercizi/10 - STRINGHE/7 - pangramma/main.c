#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di char e
 * il suo size, determina e restituisce come parametro di un dato logico che
 * indica se il testo nell�array `e un pangramma, ovvero `e un testo che
 * contiene, almeno una volta, tutte le 21 lettere dell�alfabeto italiano.
 */
void	carica_testo(char[], int *);
void	pulisci_vettore(int[]);
void	analisi_testo(char[], int, int[]);
int		analisi_pangramma(int[]);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	char	testo[MAX];
	int		s;
	int		v[MAX], pangramma;
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	carica_testo(testo, &s);
	pulisci_vettore(v);
	analisi_testo(testo, s, v);
	pangramma = analisi_pangramma(v);
	if(pangramma == 1)
		printf("Il testo inserito e' un pangramma!");
	else
		printf("Il testo inserito non e' un pangramma!");

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_testo(char testo[], int *s)
{
	printf("Inserisci testo\n");
	gets(testo);

	puts(testo);
	*s = strlen(testo);
	printf("numero lettere: %d\n", *s);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void pulisci_vettore(int v[])
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < 20; i++) v[i] = 0;
}

/*
 =======================================================================================================================
    Incrementa il vettore alla posizione della lettera che legge dal testo cos� da avere un vettore contenete ;
    il numero nuemro di volte che ogni lettera � presente nel testo.
 =======================================================================================================================
 */
void analisi_testo(char testo[], int s, int v[])
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < s; i++)
	{
		v[testo[i] - 'a']++;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int analisi_pangramma(int v[])
{
	/*~~~~~~~~~~~~~*/
	int i, pangramma;
	/*~~~~~~~~~~~~~*/

	for(i = 0; i < 20; i++)
	{
		if(v[i] == 0)
		{
			pangramma = 0;
		}
		else
			pangramma = 1;
	}

	return pangramma;
}
