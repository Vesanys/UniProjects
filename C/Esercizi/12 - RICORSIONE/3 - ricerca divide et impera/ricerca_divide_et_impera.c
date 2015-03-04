#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere un programma che dato un array di puntatori alla seguente struttura struct studente { char *nome;
    char *cognome;
    int matricola;
    };
    ricerchi un dato alunno, usando l'algoritmo di ricerca binaria ricorsiva.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct studente
{
	char	nome[20];
	char	cognome[20];
	int		matricola;
} Studente;

int		dimensione();
void	carica_studente(Studente *, const int);
void	ord_sel_min(Studente *, const int);
void	minimo(Studente *, const int, char *, int *);
void	scambia(Studente *, Studente *);
int		ric_bin_ric(char *, Studente *, int, int);
void	stampa(Studente *, const int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int dimensione()
{
	/*~~*/
	int n;
	/*~~*/

	do
	{
		printf("Quanti studenti vuoi caricare in archivio?\n");
		scanf("%d", &n);
	} while(n < 0 || n > MAX);
	return n;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_studente(Studente *studente, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	fflush(stdin);
	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Inserisci NOME %d studente :", i + 1);
		scanf("%s", &studente[i].nome);

		printf("Inserisci Cognome %d studente :", i + 1);
		scanf("%s", &studente[i].cognome);

		printf("Matricola :");
		scanf("%d", &studente[i].matricola);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int ric_bin_ric(char *nome_studente, Studente *studenti, int primo, int ultimo)
{ }

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa(Studente *studente, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf("%d. Nome %s %s \n", i + 1, studente[i].cognome, studente[i].nome);
		printf("Matricola %d \n", studente[i].matricola);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void ord_sel_min(Studente *studente, const int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	int		i, indice_min = 0;
	char	min[20];
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 0; i < n - 1; i++)
	{
		minimo(&studente[0], n - i, &min[0], &indice_min);
		scambia(&studente[i], &studente[indice_min + i]);	/* spiazamento dell indice */
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void scambia(Studente *stud1, Studente *stud2)
{
	/*~~~~~~~~~~~~~~*/
	Studente	*temp;
	/*~~~~~~~~~~~~~~*/

	*temp = *stud1;
	*stud1 = *stud2;
	*stud2 = *temp;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void minimo(Studente *studente, const int n, char minimo[], int *indice)
{
	/*~~*/
	int i;
	/*~~*/

	minimo = studente[0].cognome;
	*indice = 0;
	for(i = 0; i < n; i++)
	{
		if(strcmp(minimo, studente[i].cognome) < 0)
		{
			minimo = studente[i].cognome;
			*indice = i;
		}
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Studente	studenti[MAX];
	int			n, risultato, primo, ultimo;
	char		nome_studente[20];
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	n = dimensione();
	carica_studente(studenti, n);
	ord_sel_min(studenti, n);
	stampa(studenti, n);

	/*
	 * risultato=ric_bin_ric(&nome_studente,studente,primo,ultimo);
	 */
	system("PAUSE");
	return EXIT_SUCCESS;
}
