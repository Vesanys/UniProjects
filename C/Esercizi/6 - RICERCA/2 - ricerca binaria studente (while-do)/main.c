#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere un programma che dato un array di puntatori alla seguente struttura struct studente {char *nome;
    char *cognome;
    int matricola;
    };
    ricerchi un dato studente, utilizzando l'algoritmo di ricerca binaria.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct Studente
{
	char	*nome;
	char	*cognome;
	int		matricola;
} studente;
void	carica_studente(studente *, const int);
int		ricerca_binaria(studente *, const int, int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int ricerca_binaria(studente *student, const int nn, int chiave)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int i, inizio, fine, m;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	inizio = 0;
	fine = nn - 1;

	while(inizio <= fine)
	{
		m = (inizio + fine) / 2;
		if(student[m].matricola == chiave) return m; /* studente trovato alla posizione media */

		else if(student[m].matricola < chiave)
			inizio = m + 1;
		else
			fine = m - 1;
	}

	return -1;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_studente(studente *student, const int nn)
{
	fflush(stdin);
	for(int i = 0; i < nn; i++)
	{
		printf("Nome %d studente : ", i + 1);
		scanf("%s", &student[i].nome);
		printf("Cognome %d studente : ", i + 1);
		scanf("%s", &student[i].cognome);
		printf("Matricola %d studente : ", i + 1);
		scanf("%d", &student[i].matricola);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~*/
	studente	stud[MAX];
	int			n, indice = 0, mat;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Quanti studenti vuoi caricare? MAX 100 \n");
		scanf("%d", &n);
	} while(n < 0 || n > MAX);

	carica_studente(stud, n);
	printf("inserisci matricola dello studente da ricercare : ");
	scanf("%d", &mat);
	indice = ricerca_binaria(stud, n, mat);
	if (indice<0)printf("Studente non presente nell'archivio!\n");
	else	printf("l'indice e' %d",indice);
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
