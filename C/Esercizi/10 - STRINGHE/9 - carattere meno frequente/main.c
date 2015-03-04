#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di char e
 * il suo size, determina e restituisce come parametro di output il carattere meno
 * frequente.
 */
void	carica_testo(char[], int *);
void	pulisci_vettore(int[]);
void	analisi_testo(char[], int, int[]);
char	confronto_lettere(int[21]);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	char	testo[MAX], lettera;
	int		s;
	int		v[21], lettera_meno_usata;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	carica_testo(testo, &s);
	pulisci_vettore(v);
	analisi_testo(testo, s, v);
	lettera = confronto_lettere(v);
	printf("La lettera meno usata nel testo e': %c", lettera);

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

	for(i = 0; i < 21; i++)
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

	for(i = 0; i < s; i++)
	{
		v[testo[i] - 'a']++;
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
char confronto_lettere(int v[])
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		lettera_meno_usata, indice_lettera, i = 0;
	char	lettera;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	lettera_meno_usata = v[i];
	indice_lettera = i;
	for(i = +1; i < 20; i++)
	{
		if(lettera_meno_usata > v[i])
		{
			lettera_meno_usata = v[i];
			indice_lettera = i;
			lettera = i + 'a';
		}
	}

	return lettera;
}
