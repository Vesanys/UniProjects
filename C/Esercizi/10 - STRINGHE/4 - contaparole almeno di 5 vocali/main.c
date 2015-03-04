#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define MAX		100

/*
 * Sviluppare una function C che, data come parametro di input una stringa che
 * rappresenta un testo in italiano, determina e restituisce come parametro di
 * output il numero delle parole contenute nel testo che hanno almeno 5 vocali.
 * Nel testo le parole sono separate da un unico spazio.
 */
int conta_parole(char *, int, const int);

int conta_parole(char *testo, const int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int i, in_p, contavocali = 0, conta_p = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	in_p = FALSE;

	for(i = 0; i < n; i++)
	{
		if(testo[i] == ' ' || testo[i] == '\n' || testo[i] == '\t' || testo[i] == '\0')
			in_p = FALSE;
		else if(in_p == FALSE)
		{
			in_p = TRUE;

			if(testo[i] == 'a' || testo[i] == 'e' || testo[i] == 'i' || testo[i] == 'o' || testo[i] == 'u')
				contavocali++;

			if(contavocali >= 5)
			{
				conta_p++;
				contavocali = 0;
			}
		}

		in_p = FALSE;
	}

	return conta_p;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{

	/*~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/* fase dichiarativa: dichiaro una variabile che ospiter� il testo */
	char	testo[MAX];
	int		numero_parole = 0, n;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		puts("Inserire il testo:\n");
		gets(testo);
		n = strlen(testo);
	} while(n < 0 || n > MAX);

	numero_parole = conta_parole(testo, n); /* chiamo la funzione per contare le parole */
	printf("\nil numero di parole di almeno 5 vocali contenute nel testo e' %d\n", numero_parole);	/* stampo il numero
																									 * di parole
																									 * trovate */

	system("PAUSE");
	return EXIT_SUCCESS;
}
