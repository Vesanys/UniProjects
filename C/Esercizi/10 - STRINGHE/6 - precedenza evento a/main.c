#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

/*
 * Sviluppare una function C che, dati come parametri di input un array di char e
 * il suo size, determina e restituisce come parametro di output l'array (di size
 * 21) del numero delle occorrenze dell'evento a precede ognuna delle 21 lettere
 * dell'alfabeto italiano (cio� il numero di volte in cui accade che a precede a
 * , il numero di volte in cui accade che a precede b, il numero di volte in cui
 * accade che a precede c...).
 */
void	conta_lettere(char *, int *);
void	pulisci_vettore(int *);
void	stampa(int *);

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~*/
	char	testo[MAX];
	int		v[21];
	/*~~~~~~~~~~~~~~~*/

	puts("Inserire il testo:\n");
	gets(testo);

	pulisci_vettore(v);
	conta_lettere(testo, v);

	stampa(v);
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void stampa(int *vet)
{
	/*~~*/
	int i;
	/*~~*/

	printf("\nl' evento a precede la lettera A %d volte ", vet[0]);
	printf("\nl' evento a precede la lettera B %d volte ", vet[1]);
	printf("\nl' evento a precede la lettera C %d volte ", vet[2]);
	printf("\nl' evento a precede la lettera D %d volte ", vet[3]);
	printf("\nl' evento a precede la lettera E %d volte ", vet[4]);
	printf("\nl' evento a precede la lettera F %d volte ", vet[5]);
	printf("\nl' evento a precede la lettera G %d volte ", vet[6]);
	printf("\nl' evento a precede la lettera H %d volte ", vet[7]);
	printf("\nl' evento a precede la lettera I %d volte ", vet[8]);
	printf("\nl' evento a precede la lettera L %d volte ", vet[9]);
	printf("\nl' evento a precede la lettera M %d volte ", vet[10]);
	printf("\nl' evento a precede la lettera N %d volte ", vet[11]);
	printf("\nl' evento a precede la lettera O %d volte ", vet[12]);
	printf("\nl' evento a precede la lettera P %d volte ", vet[13]);
	printf("\nl' evento a precede la lettera Q %d volte ", vet[14]);
	printf("\nl' evento a precede la lettera R %d volte ", vet[15]);
	printf("\nl' evento a precede la lettera S %d volte ", vet[16]);
	printf("\nl' evento a precede la lettera T %d volte ", vet[17]);
	printf("\nl' evento a precede la lettera U %d volte ", vet[18]);
	printf("\nl' evento a precede la lettera V %d volte ", vet[19]);
	printf("\nl' evento a precede la lettera Z %d volte ", vet[20]);
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void pulisci_vettore(int *v)
{
	for(int i = 0; i < 21; i++) v[i] = 0;
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void conta_lettere(char *a, int *vet)
{
	/*~~~~~*/
	int i, n;
	/*~~~~~*/

	n = strlen(a);
	for(i = 0; i < n; i++)
	{
		if(a[i] == 'a')
		{
			switch(a[i + 1])
			{
			case 'a':	vet[0]++; break;
			case 'b':	vet[1]++; break;
			case 'c':	vet[2]++; break;
			case 'd':	vet[3]++; break;
			case 'e':	vet[4]++; break;
			case 'f':	vet[5]++; break;
			case 'g':	vet[6]++; break;
			case 'h':	vet[7]++; break;
			case 'i':	vet[8]++; break;
			case 'l':	vet[9]++; break;
			case 'm':	vet[10]++; break;
			case 'n':	vet[11]++; break;
			case 'o':	vet[12]++; break;
			case 'p':	vet[13]++; break;
			case 'q':	vet[14]++; break;
			case 'r':	vet[15]++; break;
			case 's':	vet[16]++; break;
			case 't':	vet[17]++; break;
			case 'u':	vet[18]++; break;
			case 'v':	vet[19]++; break;
			case 'z':	vet[20]++; break;
			case ' ':	break;
			default:	break;
			}
		}
	}
}
