#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 * Sviluppare una function C che, dati come parametri di input un array di char e
 * il suo size, determina e restituisce come parametro di output il carattere piu
 * frequente.
 */
void	carica_testo(char *, int *);
void	pulisci_vettore(int *);
void	analisi_testo(char *, int, int *);
char	confronto_lettere_piuusata(int[21]);
char	confronto_lettere_menousata(int[21]);

/*
 =======================================================================================================================
    char individua_lettera(int [],int);
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	char	testo[MAX], lettera;
	int		v[21], s;
	char	lettera_piu_usata, lettera_meno_usata;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	carica_testo(testo, &s);
	pulisci_vettore(v);
	analisi_testo(testo, s, v);
	lettera_piu_usata = confronto_lettere_piuusata(v);
	lettera_meno_usata = confronto_lettere_menousata(v);

	/*
	 * lettera=individua_lettera(v,lettera_piu_usata);
	 */
	printf("La lettera piu' usata nel testo e': %c \n", lettera_piu_usata);
	printf("La lettera piu' usata nel testo e': %c \n", lettera_meno_usata);

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_testo(char *testo, int *s)
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
void pulisci_vettore(int *v)
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
void analisi_testo(char *testo, int s, int *v)
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
char confronto_lettere_piuusata(int v[MAX])
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		lettera_piu_usata, indice_lettera, i = 0;
	char	lettera;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	lettera_piu_usata = v[i];
	indice_lettera = i;
	for(i = +1; i < 20; i++)
	{
		if(lettera_piu_usata < v[i])
		{
			lettera_piu_usata = v[i];
			indice_lettera = i;
			lettera = i + 'a';
		}
	}

	return lettera;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
char confronto_lettere_menousata(int v[MAX])
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int		lettera_piu_usata, indice_lettera, i = 0;
	char	lettera;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	lettera_piu_usata = v[i];
	indice_lettera = i;
	for(i = +1; i < 20; i++)
	{
		if(lettera_piu_usata > v[i])
		{
			lettera_piu_usata = v[i];
			indice_lettera = i;
			lettera = i + 'a';
		}
	}

	return lettera;
}
