#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 =======================================================================================================================
    Modificare il seguente codice in modo tale che il risultato della visualizzazione sia zero ;
    per ottenere cio modifichiamo il numero di caratteri del confronto da 7 a 6 in modo tale che il numero dei
    caratteri presenti nella stringa a siano uguali ai caratteri presenti nel puntatore p ;
    cio restituisce 0
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~~~*/
	char	*p;
	char	a[] = "Musica";
	/*~~~~~~~~~~~~~~~~~~~*/

	p = strchr("La mia Musica preferita non ha prezzo", 'M');
	printf("%d\n", strncmp(p, a, 6));	/* strncmp() ritorna un intero minore, uguale o maggiore di 0 a seconda che s1
										 * sia (o i primi n caratteri siano, in questo caso si) rispettivamente minore,
										 * uguale o maggiore di s2 */

	system("pause");
	return 0;
}
