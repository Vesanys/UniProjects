#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//Modicare il seguente codice in modo tale che il risultato della visualizzazione sia la parola
//"Comprimere"

int main()
{
char *p1, *p2,*p3;
p1 = strchr(" Comp ",' ');
p2 = strchr("attare rare rimere",'r');
p3 = strncat(p1[5],p2[13]);

printf("stringa finale : %s ",*p3);

    system("PAUSE");
    return EXIT_SUCCESS;
}
