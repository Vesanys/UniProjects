#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "header.h"
/*
 =======================================================================================================================
 =======================================================================================================================
 */

void stampa(disco *x, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf("%d Autore: %s \n", i + 1, x[i].nome_autore);
		printf(" Nome disco: %s \n", x[i].titolo);
		printf(" Prezzo Disco: %f \n", x[i].prezzo);
		printf("Codice: %d\n", i);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa_con_flag(disco *x, const int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		printf("%d Autore: %s \n", i + 1, x[i].nome_autore);
		printf(" Nome disco: %s \n", x[i].titolo);
		printf(" Prezzo Disco: %f \n", x[i].prezzo);
		printf("Codice: %d\n", i);
		printf("Flag: %d\n", x[i].flag);
	}
}


/*
 =======================================================================================================================
 =======================================================================================================================
 */
void carica(disco *cd, int nn)
{
	fflush(stdin);
	for(int i = 0; i < nn; i++)
	{
		printf("Inserisci il titolo del %d disco \n", i + 1);
		scanf("%s", &cd[i].titolo);
		printf("Inserisci il nome dell autore del disco \n");
		scanf("%s", &cd[i].nome_autore);
		printf("Inserisci il prezzo del disco \n");
		scanf("%f", &cd[i].prezzo);
		printf("Disco presente o in prestito? 1 Presente 0 In prestito\n");
		scanf("%1d", &cd[i].flag);
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int massimo(disco *x, const int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~*/
	float	max = x[0].prezzo;
	int		i, indice_max;
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 1; i < n; i++){
		if(x[i].prezzo > max)
		{
			max = x[i].prezzo;
			indice_max = i;
		}
    }

	return indice_max;
}
void    ricerca_sequenziale(disco *x,int n,int *k,char *chiave,disco *temp)
{
        int i;
        for(i=1;i<n;i++)
        {
                        if(strcmp(x[i].nome_autore,chiave)==0){
                                                               temp[*k]=x[i];
                                                               (*k)++;
                                                              
                                                               }
                                                               }
}
