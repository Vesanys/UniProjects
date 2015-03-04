#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 -----------------------------------------------------------------------------------------------------------------------
    Scrivere una funzione che dati in input due array di puntatori alla seguente struttura struct prodotto {char *nome;
    int codice;
    double prezzo;
    };
    verichi se i due array di struct sono uguali.
 -----------------------------------------------------------------------------------------------------------------------
 */
typedef struct prodotto
{
	char	nome[20];
	int		codice;
	double	prezzo;
} Prodotto;
void	carica_prodotti(Prodotto **, const int);
int		uguaglianza(Prodotto **, Prodotto *, const int);

/*
 =======================================================================================================================
 =======================================================================================================================
 */

int uguaglianza(Prodotto **v1, Prodotto **v2, const int nn)
{
	/*~~~~~~~~~~~~~*/
	int u = 1, i = 0;
	/*~~~~~~~~~~~~~*/

	while(i < nn && u)
	{

		/*
		 * controllo se i codici dei prodotti dei due array sono uguali e se anche i nomi
		 * lo sono ;
		 * la funz strcmp confronta le stringhe e ritorna 0 se sono uguali appena incontra
		 * un elemento diverso esce
		 */
		if(v1[i]->codice != v2[i]->codice || strcmp(v1[i]->nome, v2[i]->nome) != 0) u = 0;
		i++;
	}

	return u;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica_prodotti(Prodotto **prod1, const int nn)
{
	/*~~*/
	int i;
	/*~~*/

	fflush(stdin);
	for(i = 0; i < nn; i++)
	{
		printf("Nome %d prodotto : ", i + 1);
		scanf("%s", &prod1[i]->nome);

		printf("Codice %d prodotto Es. 11,12,13...1n : ", i + 1);
		scanf("%d", &prod1[i]->codice);

		printf("Prezzo %d prodotto : ", i + 1);
		scanf("%lf", &prod1[i]->prezzo);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int LeggiNumero(int *letto)
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	int		dato;
	char	val[100] = { 0 };
	char	val2[100] = { 0 };
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	do
	{
		printf("Quanti prodotti vuoi caricare? \n");
		gets(val);

		dato = atoi(val);
		printf("dato %d", dato);
		itoa(dato, val2, 10);

		if(strcmp(val, val2) == 0)
		{
			*letto = dato;
			return 1;
		}

		if(dato == 0)
		{
			printf("Warning!\n");
		}
	} while(*letto <= 0 || *letto > MAX);
	return 0;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	Prodotto	*v1[MAX], *v2[MAX];
	int			uguali = 0, posiz1 = 0, posiz2 = 0, num, letto;
	char		n;
	double		minim1 = 0, minim2 = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/* x controllare che non si inserisca una lettera??? */
	num = LeggiNumero(&letto);

	printf("Carico Primo array : \n");
	carica_prodotti(&v1, n);
	printf("Carico Secondo array : \n");
	carica_prodotti(&v2, n);

	uguali = uguaglianza(&v1, &v2, n);

	/* controllo se effettivamente gli array di struct caricati sono uguali */
	if(uguali)
		printf("Array di prodotti uguali \n");
	else
		printf("Array diversi\n");

	system("PAUSE");
	return EXIT_SUCCESS;
}
