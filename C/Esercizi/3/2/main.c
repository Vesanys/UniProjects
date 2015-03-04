#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 =======================================================================================================================
    Modificare il seguente codice in modo tale che il risultato della visualizzazione sia zero
 =======================================================================================================================
 */
int main()
{
	/*~~~~~~~~~~~~~~~~~*/
	char	*p, b[10];
	char	a[] = "PASS";
	/*~~~~~~~~~~~~~~~~~*/

	p = strchr("inserisci la password", 'l');
	strncpy(b, &p[3], strlen(p) - 7);
	printf("%d\n", strcmp(a, strupr(b)));

	system("PAUSE");
	return EXIT_SUCCESS;
}
