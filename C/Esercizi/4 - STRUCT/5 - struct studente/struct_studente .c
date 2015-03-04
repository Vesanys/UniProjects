#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una funzione che ha come input i dati che identicano uno studente (nome, cognome, matricola) e che
    restituisce in output una struttura contenente i dati in input e il libretto univesritario con al massimo 20 esami.
    ;
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct studente
{
	int		matricola;
	char	nome[50];
	int		num_esami;
} Studente;

typedef struct Esame
{
	char	nome[40];
	int		voto;
} esame;

/* prototipi */
void	carica_studente(Studente *);
void	carica_esami(esame *, Studente *);
void	stampa_libretto(Studente *, esame *);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

void carica_esami(esame *es, Studente *stud)
{
	/*~~*/
	int i;
	/*~~*/

	fflush(stdin);

	for(i = 0; i < (stud->num_esami); i++)
	{
		fflush(stdin);
		printf("Nome %d esame sostenuto: ", i + 1);
		gets(es[i].nome);

		do
		{
			printf("Voto (>= 18 e <= 30):");

			scanf("%d", &es[i].voto);
		} while(es[i].voto < 18 || es[i].voto > 30);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_studente(Studente *studente)
{
	printf("Inserisci COGNOME e NOME studente :");
	gets(studente->nome);

	printf("Matricola :");
	scanf("%d", &studente->matricola);

	do
	{
		printf("Esami sostenuti max=20:");
		scanf("%d", &studente->num_esami);
	} while(studente->num_esami <= 0 || studente->num_esami > 20);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa_libretto(Studente *stud, esame *es)
{
	/*~~*/
	int i;
	/*~~*/

	printf("Nome studente inserito :\n");
	puts(stud->nome);
	printf("\nMatricola : %d", stud->matricola);
	printf("\nNumero esami sostenuti : %d", stud->num_esami);
	printf("\nLibretto universitario: \n");
	for(i = 0; i < stud->num_esami; i++) printf("%s voto: %d\n", es[i].nome, es[i].voto);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~*/
	Studente	stud;
	esame		es[MAX];
	/*~~~~~~~~~~~~~~~~*/

	carica_studente(&stud);
	carica_esami(es, &stud);
	system("cls");
	stampa_libretto(&stud, es);

	system("PAUSE");
	return EXIT_SUCCESS;
}
