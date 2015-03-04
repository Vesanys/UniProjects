#include <stdio.h>
#include <stdlib.h>

/*
 * Scrivere un programma che simuli un salvadanaio. L'utente puo inserire e
 * prelevare soldi. Visualizzare salvadanaio vuoto se non ci sono soldi. Il numero
 * di operazioni di inserimento e prelievo sono decise dall'utente. L'inserimento
 * e il prelievo devono avvenire con la chiamata a due procedure dierenti.
 */
float	versamento(float);
float	prelievo(float);
void	saldo(float);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

float prelievo(float prel)
{
	printf("Quanto vuoi prelevare? :\n");
	scanf("%f", &prel);
	return prel;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void saldo(float contoattuale)
{
	printf("Il saldo attuale e': %4.2f euro\n", contoattuale);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
float versamento(float vers)
{
	printf("Quanto vuoi versare? :\n");
	scanf("%f", &vers);
	return vers;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~*/
	float	conto = 0;
	int		risp, scelta;
	/*~~~~~~~~~~~~~~~~~*/

	printf("salvadanaio\n");
	do
	{
		printf("Scegliere l operazione da eseguire :\n");
		printf("1. Versamento \n");
		printf("2. Prelievo \n");
		printf("3. Saldo \n");
		printf("Inserire scelta -> ");
		scanf("%d", &risp);

		switch(risp)
		{
		case 1:
			conto += versamento(conto);
			break;

		case 2:
			if(conto <= 0)
				printf("Operazione non consentita, conto vuoto!\n");
			else
				conto -= prelievo(conto);
			break;

		case 3:
			saldo(conto);
			break;

		default:
			printf("operazione non consentita\n");
			break;
		}

		printf("vuoi fare un altra operazione? 0 no 1 si\n");
		scanf("%d", &scelta);
		system("cls");
	} while(risp < 1 || risp > 3 || scelta == 1);
	system("pause");
	return 0;
}
