#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 -----------------------------------------------------------------------------------------------------------------------
    Individuare e correggere gli errori nel seguente programma in modo che il risultato sia 18 e 30
 -----------------------------------------------------------------------------------------------------------------------
 */
struct studente
{
	char	*nome;
	char	*cognome;
	short	libretto[20];
};
typedef struct studente Studente;

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Studente	*a, b = { "Mario", "Rossi", { 18, 30 } };
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	a = &b; /* per ottenere il risultato richiesto basta far puntare a all elemento b */

	printf("%d\n", a->libretto[0]);
	printf("%d\n", a->libretto[1]);

	system("PAUSE");
	return EXIT_SUCCESS;
}
