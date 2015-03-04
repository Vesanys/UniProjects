#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una funzione che dati in input due array ordinati di puntatori alla seguente struttura struct studente
    {char *nome;
    char *cognome;
    int matricola;
    };
    restituisca in output l'array fusione dei due array. La fusione deve avvenire in base al campo matricola.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct studente
{
	int		matricola;
	char	*nome;
	char	*cognome;
} Studente;

/* prototipi */
void	carica_studente(Studente *, const int);
void	stampa(Studente *, const int);
int		dimensione();
void	fusione(Studente *, Studente *, Studente *, const int, const int, int *);

/*
 =======================================================================================================================
 Input di dimensione e vari controlli all'input
 =======================================================================================================================
 */

int dimensione()
{
	/*~~*/
	int n;
	/*~~*/

	do
	{
		printf("Inserisci la dimensione \n");
		scanf("%d", &n);
	} while(n < 0 || n > MAX);
	return n;
}

/*
 =======================================================================================================================
 Caricamento struct da Input
 =======================================================================================================================
 */
void carica_studente(Studente *studente, const int n)
{
     int i;
     fflush(stdin);
	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Inserisci NOME studente :");
		scanf("%s",&studente[i].nome);
		printf("Inserisci COGNOME studente :");
		scanf("%s",&studente[i].cognome);
		printf("Matricola (es 0124000234 :");
		scanf("%d", &studente[i].matricola);
	}
}

/*
 =======================================================================================================================
 FUSIONE
 =======================================================================================================================
 */
void fusione(Studente *s1, Studente *s2, Studente *s3, const int n, const int m, int *k)
{
	/*~~~~~~~~~~~~~*/
	int i = 0, j = 0;
	/*~~~~~~~~~~~~~*/

	while(i < n && j < m)
	{
		if(s1[i].matricola < s2[j].matricola)
		{
			s3[*k]= s1[i];
			i++;
			printf("%d %s",s3[*k].matricola, s3[*k].nome);
		}
		else
		{
			s3[*k]= s2[j];
			j++;
		}
		(*k)++;
	}

	while(i < n)
	{
		s3[*k]= s1[i];
		i++;
		(*k)++;
	}

	while(j < m)
	{
		s3[*k]= s2[j];
		j++;
			printf("%d",s3[*k].matricola);
		(*k)++;
	}
}

/*
 =======================================================================================================================
 Sottoprogramma di Stampa
 =======================================================================================================================
 */
void stampa(Studente *stud, const int k)
{
     int i;
	for(i = 0; i < k; i++) {
                              printf("\n Studente[%d] nome: %s %s ", i, stud[i].nome,stud[i].cognome);
                              printf("\n Matricola = %d", stud[i].matricola);
                              }
}

/*
 =======================================================================================================================
 MAIN
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Studente	s1[MAX], s2[MAX], s3[MAX];
	int			n, m, k = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    printf("Dimensione primo array \n");
	n = dimensione();
	printf("Dimensione secondo array \n");
	m = dimensione();
	printf("Carico il primo array ORDINATO\n");
	carica_studente(s1, n);
	printf("Carico il secondo array ORDINATO\n");
	carica_studente(s2, m);
	fusione(s1, s2, s3, n, m, &k);
	printf("Fusione array ORDINATI\n");
	system("pause");
	stampa(s3, k);

	system("PAUSE");
	return EXIT_SUCCESS;
}
