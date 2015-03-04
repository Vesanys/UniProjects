#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"



int main ()
{
    
int i, j,intensita,punteggio_giocatore=0,punteggio_pc=0,ncr,ncc,conta_vittorie_giocatore=0,conta_vittorie_pc=0;


char matrice [4][5] = { {'_','_','_','_','_'},
                        {'_','G','P','G','_'},
                        {'_','R','P','G','_'},
                        {'_','G','P','G','_'},
                        };

stampa(matrice);
srand(time(0));

intensita=rand() %10;

                 for(i=0;i<100;i++) /*Numero di simulazioni*/
                 {
                                    for(j=0;j<500;j++){ /*Numero di lanci per simulazione*/
                                                        do{ 
                                                            ncr=rand() %4;
                                                            ncc=rand() %5;
                                                            }while(matrice[ncr][ncc]=='R'); 

                                                            if(matrice[ncr][ncc]== 'R' || matrice[ncr][ncc]== 'G' || matrice[ncr][ncc]== '_')punteggio_giocatore++; /*Stabilizazzione punteggio*/
                                                            else punteggio_pc++;




                                                            }
                                                            
                                                            printf("fine %d gara\n",i+1); 
                                                            printf("punteggio giocatore: %d\n",punteggio_giocatore);
                                                            printf("punteggio pc: %d\n",punteggio_pc);
                                                            system("pause");
                                                            system("cls");
                                                            
                                                            } 
                                                            /*Contatore vincite giocatore*/

                                                            if (punteggio_giocatore > punteggio_pc) conta_vittorie_giocatore++;
                                                            else conta_vittorie_pc++; /*Contatore punteggio pc*/

                                                            if (punteggio_giocatore > punteggio_pc) printf("Vince il giocatore con il punteggio %d\n",punteggio_giocatore);
                                                            else printf ("Vince il PC\n");

                                                            

system("pause");
return 0;
}
