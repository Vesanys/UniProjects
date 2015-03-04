#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define MAX		100
int conta_parole(char *, const int);

/*
 =======================================================================================================================
 Scrivere un programma che conti il numero di parole in un testo
 =======================================================================================================================
 */
int conta_parole(char *testo, const int n)
{

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/* dichiaro 2 indici */
	int i, in_p, conta_c = 0, conta_p = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/* imposto l inizio parola a FALSO le parole vengono determinate dagli spazi */
	in_p = FALSE;

	for(i = 0; i <= n; i++)
	{

		/*
		 * se l i-esimo carattere di solito il 1 della stringa � uguale a uno spazio o a
		 * un "a capo" o a una tabulazione orizzontale
		 */
		if(testo[i] == ' ' || testo[i] == '\n' || testo[i] == '\t' || testo[i] == '\0')
			in_p = FALSE;
		else if(in_p == FALSE)
		{
			in_p = TRUE;
			conta_c++;
		}

		in_p = FALSE;

		if(conta_c == 3 && (testo[i] == ' ' || testo[i] == '\0'))
		{
			conta_p++;
			conta_c = 0;
		}
	}

	return conta_p;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/* fase dichiarativa: dichiaro una variabile che ospiter� il testo */
	char	testo[MAX];
	int		j, n, i = 0, numero_parole;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		puts("Inserire il testo:\n");
		gets(testo);
		n = strlen(testo);
	} while(n < 3);

	numero_parole = conta_parole(testo, n); /* chiamo la funzione per contare le parole */
	printf("conta_parole\nnumero di parole formate da tre lettere = %d\n", numero_parole);	/* stampo il numero di
																							 * parole trovate */

	system("PAUSE");
	return EXIT_SUCCESS;
}
