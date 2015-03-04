#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Studente{
int matricola;
char nome[50];
int num_esami;
};

typedef Studente * Archivio;
Archivio crea_archivio(int &);
void crea_studente(Studente & studente,int num);
void inserisci_studente(Studente studente ,Archivio archivio,int & nentry);
int ricerca_studente(const Archivio archivio,int primo,int ultimo,int &pos,int x);
void stampa_dati( const Archivio,int );
void stampa_studente(const Archivio,int );
void distruggi(Archivio &archivio);
int main()
{
  Archivio archivio;
  Studente studente;
  int n,nentry=0,ris,primo=0,pos,x,f=0;
 do{
   do{
         printf("Gestione di un archivio di studenti\n");
         printf("1) Crea archivio\n");
         printf("2) Crea studente\n");
         printf("3) Ricerca studente\n");
         printf("4) Stampa dati\n");
         printf("5) Stampa studente\n");
         printf("6) Distruggi archivio\n");
         printf("7) Esci\n");
         printf("Scegliere l'operazione da eseguire -> ");
         scanf("%d",&ris);
         }while(ris<1 || ris > 7);
         
              switch(ris){
                                case 1:
                                       archivio=crea_archivio(n);
                                       system("pause");
                                       system("cls");
                                       break;
                                case 2:
                                        do{
                                        crea_studente(studente,n);
                                        inserisci_studente(studente,archivio,nentry);
                                        }
                                        while(nentry<n);
                                        break;
                                case 3: 
                                        printf("Inserire matricola da ricercare :\n");
                                        scanf("%d",&x);
                                        f=ricerca_studente(archivio,primo,n,pos,x);
                                        if(f)printf("matricola trovata! in posizione %d",pos);
                                        else printf("matricola non presente");
                                        system("pause");
                                        system("cls");
                                        break;
                                case 4:
                                        if (n>0)stampa_dati(archivio,n);
                                        else printf("Archivio vuoto!\n");
                                         system("pause");
                                         system("cls");
                                         break;
                                case 5:  printf("Qual'è la matricola dello studente del quale si vuole stampare i dati?");
                                         scanf("%d",&x);
                                         f=ricerca_studente(archivio,primo,n,pos,x);
                                         if(f)
                                         stampa_studente(archivio,pos);
                                         else printf("Matricola non presente nell'archivio!\n");
                                         system("pause");
                                         system("cls");
                                         break;
                                case 6:
                                        distruggi(archivio);
                                        break;
                                         
              }
         }
  while(ris!=7);
  system("PAUSE");	
  return 0;
}
Archivio crea_archivio(int & n)
{

    printf("quante entry avra' l'archivio? -->");
    scanf("%d",&n);
    Studente *v=new Studente [n]; //alloca spazio in area heap x n entry
    return v;   //restituisce il puntatore all area heap allocata dinamicamente
}
void crea_studente(Studente & studente,int num)
{
   printf("Inserimento dati  studente :\n");
   printf("Nome :");
  // cin.ignore();
   fgets(studente.nome,50,stdin);
   printf("Matricola :");
   scanf("%d",studente.matricola);
   printf("Numero esami sostenuti :");
   scanf("%d",studente.num_esami);
   system("cls");
 
}
void inserisci_studente(Studente studente,Archivio archivio,int & nentry)
{
   archivio[nentry]=studente;//caricamento dell oggetto studente nel vettore archivio in posizione nentry
   nentry++;
}
int ricerca_studente(const Archivio archivio,int primo,int ultimo,int &pos,int x)
{
int found=0;
 
 for(int i=0;(i<ultimo)&&(!found);i++)
 {
     if(archivio[i].matricola==x){found=1;
                                   pos=i;
                 }
 }
 return found;
}
void stampa_dati(const Archivio archivio,int entry)
{ 
      for(int i=0;i<entry;i++){
                                 printf("nome studente :%s",archivio[i].nome);
                                 printf("\nmatricola :%d",archivio[i].matricola);
                                 printf("esami sostenuti :%d",archivio[i].num_esami);
                                 printf("\n");
      }
}
void stampa_studente(const Archivio archivio,int pos)
{
                                 printf("nome studente :%s",archivio[pos].nome);
                                 printf("\nmatricola :%d",archivio[pos].matricola);
                                 printf("esami sostenuti :%d",archivio[pos].num_esami);
                                 printf("\n");
}  
void distruggi(Archivio &archivio)
{
   delete [] archivio;

}
