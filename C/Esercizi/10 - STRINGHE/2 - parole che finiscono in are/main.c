#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*
 * Sviluppare una function C che, data come parametro di input una stringa che
 * rappresenta un testo in italiano, determina e restituisce come parametro di
 * output il numero di parole che terminano in are contenute nel testo. Nel testo
 * le parole sono separate da un unico spazio.
 */
int return_are(char *, int const);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~*/
	char	testo[MAX];
	int		n_occorrenze = 0, n;
	/*~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		puts("Inserire il testo:\n");
		gets(testo);
		n = strlen(testo);
	} while(n < 3);

	n_occorrenze = return_are(testo, n);

	printf("il numero di parole che finiscono in 'are' contenute nel testo sono : %d\n", n_occorrenze);
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int return_are(char *a, int const nn)
{
	/*~~~~~~~~~~~~*/
	int i, cont = 0;
	/*~~~~~~~~~~~~*/

	for(i = 3; i <= nn; i++)
		if(a[i - 3] == 'a' && a[i - 2] == 'r' && a[i - 1] == 'e') cont++;

	return cont;
}
