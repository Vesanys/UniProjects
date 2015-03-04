#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di char e
 * il suo size, determina e restituisce come parametro di output l'array (di size
 * 21) del numero delle occorrenze delle 21 lettere dell'alfabeto italiano
 */
void	carica_testo(char[], int *);
void	pulisci_vettore(int[]);
void	analisi_testo(char[], int, int[]);
void	stampa_vettore_occorrenze(int[]);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int main()
{
	/*~~~~~~~~~~~~~~~~~~*/
	char	lettera = 'a';
	char	testo[MAX];
	int		s;
	int		v[21];
	/*~~~~~~~~~~~~~~~~~~*/

	carica_testo(testo, &s);
	pulisci_vettore(v);
	analisi_testo(testo, s, v);
	stampa_vettore_occorrenze(v);

	system("PAUSE");
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
	printf("%d\n", *s);
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

	for(i = 0; i < 20; i++)
	{
		v[i] = 0;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void analisi_testo(char testo[], int s, int v[])
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < s; i++) v[testo[i] - 'a']++;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa_vettore_occorrenze(int v[])
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < 20; i++)
	{
		printf("L'occorenza della lettera %c dell'alfabeto e': %d\n", i + 'a', v[i]);
	}
}
