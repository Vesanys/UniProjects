#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
void conta_parole(char*testo,int* numero_parole);
void conta_parole(char*testo,int*conta_p)
{
     //dichiaro 2 indici
     int i=0,in_p;
     //dichiaro il puntatore che servirà a mantenere il conto delle parole
     *conta_p =0;
     //imposto l inizio parola a FALSO le parole vengono determinate dagli spazi
     in_p=FALSE;
     //finchè l' i-esima lettera è diversa dal carattere di fine stringa lui cicla
     while(testo[i] != '\0')
     {
                    //se l i-esimo carattere di solito il 1 della stringa è uguale a uno spazio o a un "a capo" o a una tabulazione orizzontale 
                    if(testo[i] == ' '|| testo[i]== '\n' || testo[i]== '\t')in_p=FALSE;//significa che nn è iniziata ancora una parola
                    else if(in_p== FALSE){
                         in_p= TRUE;//imposto inizio parola a VERO
                         (*conta_p)++;//incremento il puntatore che conta le parole
                         }
                         i++;//qui incremento l indice che scorre nel testo
                         }
                       
}
int main()
{
    //fase dichiarativa: dichiaro una variabile che ospiterà il testo,dei separatori definiti da me, e un puntatore
          char testo[100],separatori[]={' ','\n','\t','\0'},*token;
          int numero_parole,j;
         
         
          gets(testo);//prendo il testo dall input
          conta_parole(testo,&numero_parole);//chiamo la funzione per contare le parole
          printf("conta_parole\nnumero di parole = %d\n",numero_parole);//stampo il numero di parole trovate
          /* uso di strtok*/
          
          printf("elenco delle parole (tokenestratti con strtok):\n");
          j =1;
          
          printf("1-sima parola = %s\n",strtok(testo,separatori));
          while((token= strtok('\0',separatori)) !='\0') 
          {
                        j++ ;
                        printf("%d-sima parola = %s\n",j,token);
          }
          system("PAUSE");
    return EXIT_SUCCESS;
}
