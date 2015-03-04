#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
 =======================================================================================================================
    Scrivere un programma che simuli un sistema per determinare un codice segreto. Il programmatore definisce un codice
    di 5 lettere dell'alfabeto e in maniera casuale simula dei codici fino a che non trova quello esatto. Visualizzare
    il numero di prove effettuate.
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	char	codice[] = "mammt", v[5];
	char	carat;
	int		trovato = 0, cont = 0, i = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	srand(time(NULL));
	do
	{
		carat = rand() % 26 + 'a';	/* funzione per generare caratteri casuali */
		if(carat == codice[i])v[i++] = carat;
		cont++;
		if(i > 4) trovato = 1;
	} while(trovato == 0 && cont < 1000);
	if(cont >= 1000)
		printf("Programma terminato per overflow di limite prove consentito \n");
	else
		printf("Programma terminato perche il codice e' stato trovato con %d numero di tentativi\n", cont);
	for(int i = 0; i <= 4; i++) printf("codice trovato : %c \n", v[i]);
	system("PAUSE");
	return EXIT_SUCCESS;
}
