/*$T  01/21/11 19:55:53 */

/* JOSEF VITANOSTRA 
L'esercizio consisteva nel prendere in input una frase da tastiera (caratteri maiuscoli) 
spezzarla in coppie formate da 2 lettere ricercare le coppie nella matrice e codificarle, 
inserendo un eventuale carattere X tra le coppie che duirante la suddivisione sarebbero risultate uguali.
Il programma presenta 2 main differenti) il primo Main contiene la Matrice di Sostituzione statica data nella traccia 
nel 2 Main invece la Matrice di Sostituzione risulta essere una permutazione random della matrice di partenza.
*/


/*$6
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      Algoritmi per la cifratura/decifratura di un messaggio. 
      Sviluppare una coppia di algoritmi, implementati come function, per crittografare e decrittografare un messaggio. 
      L'algoritmo si basa sulla cosiddetta cifratura polialfabetica, che consiste nel trasformare il messaggio in un 
      testo di lunghezza maggiore o uguale a quella del messaggio, detto il testo cifrato, utilizzando una matrice di caratteri 
      (prefissata), detta matrice di sostituzione. Il messaggio da crittografare viene dapprima partizionato in coppie di 
      lettere adiacenti; se in tale partizionamento accade che una coppia è formata dalla stessa lettera, allora si 
      inserisce una X tra le due. 
      Per esempio, il messaggio : LET US MEET AT NOON viene partizionato in LE TU SM EX ET AT NO ON. 
      Si è inserita una X tra le due E, ma non tra le due O, che si trovano in coppie diverse. 
      Si consideri la seguente matrice di sostituzione: 
              
              8 J E Q D N 5 O 
              P U 3 A R F L W 
              4 V C 2 T M B I 
              K 7 Z S G X H Y 
      
      Ogni coppia di lettereviene crittografata nel seguente modo: 
           a. se le lettere sono nella stessa riga della matrice di sostituzione, le due lettere da inserire nel testo 
           cifrato saranno le lettere immediatamente a destra nella stessa riga. Ogni riga e' considerata circolare. 
           Per esempio, la coppia TI viene crittografata come M4. 
           b. se le lettere sono nella stessa colonna della matrice di sostituzione, le due lettere da inserire nel 
           testo cifrato saranno le lettere immediatamente sotto nella stessa colonna. 
           Ogni colonna e' considerata circolare. Per esempio, la coppia RG viene crittografata come TD. 
           c. se le lettere appaiono in differenti righe e colonne della matrice di sostituzione, ognuna delle due lettere 
           sara' crittografata con la lettera nella stessa riga ma nella colonna dell'altra lettera.. 
           Per esempio, la coppia LE viene crittografata come 35. Il messaggio LET US MEET AT NOON viene quindi 
           crittografato in 35VRX2NZDCR25885. 
     
      Il main legge da tastiera il messaggio da crittografare l'equivalente di LET US MEET AT NOON nell'esempio), 
      chiama la function di cifratura (passando come parametro il messaggio e la matrice di sostituzione), 
      che restituisce il teso cifrato, visualizza il testo cifrato, chiama la function di decifratura, passando 
      come parametro il testo cifrato e la matrice di sostituzione, visualizza il messaggio decifrato, che deve 
      coincidere con il messaggio di partenza. Usare solo lettere maiuscole. Usare le stringhe per rappresentare il 
      messaggio e il testo crittografato e decrittografato Fare una versione alternativa del main, in cui la 
      matrice di sostituzione e' una permutazione casuale della matrice precedente, usando la function rand(), 
      il cui prototipo e' in <stdlib.h>, per generare gli interi casuali per lo scambio a coppie di elementi della 
      matrice. Si ricorda che, se numero_casuale e' dichiarata di tipo int, allora la chiamata numero_casuale=rand()%(n+1);
      genera un numero casuale intero (distribuzione uniforme) nell'insieme (0,1,2,..n). Usare sempre la srand() per
      rendere automatica la scelta iniziale del seed della sequenza di numeri casuali. Nella Relazione si deve
      riportare l'analisi della complessità di tempo dell'algoritmo (operazione dominante: confronto)
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define MAX 100
#include "prototipi.h"

/*
 =======================================================================================================================
      MAIN
 =======================================================================================================================
 */
int main()
{
      /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
      int   n, i, cont = 0, m, nn = 0, scelta, ncr, ncc, ncr2, ncc2, combinazioni;
      
      char  matrice_di_sostituzione[4][9] =
      {
            { '8', 'J', 'E', 'Q', 'D', 'N', '5', 'O', },
            { 'P', 'U', '3', 'A', 'R', 'F', 'L', 'W', },
            { '4', 'V', 'C', '2', 'T', 'M', 'B', 'I', },
            { 'K', '7', 'Z', 'S', 'G', 'X', 'H', 'Y', },
      };
      //pulisco le stringhe che utilizzerò
      char  messaggio[MAX] = { 0 },
      messaggio_cifrato[MAX] = { 0 },
      messaggio_decodificato[MAX] = { 0 },
      messaggio_X[MAX] = { 0 },
      messaggio_senza_spazi[MAX] = { 0 },
      temp;
      /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

      do
      {
            printf("Cifratura-Decifratura messaggi\n");
            printf("Scegli l'operazione da eseguire: \n");
            printf("1. Main con Matrice di sostituzione statica \n");
            printf("2. Main con Matrice di sostituzione Random \n");
            printf("3. Exit \n");
            printf("Inserisci la scelta -> ");
            scanf("%1d", &scelta);
            switch(scelta)
            {
            case 1:
                  {

                        fflush(stdin);          /* SCARICO IL BUFFER */
                        printf("Inserisci il messaggio da crittografare: \n");
                        gets(messaggio);        /* prendo il messaggio in input con gli spazi */

                        strupr(messaggio);      /* funzione per la conversione di stringhe da minuscolo a Maiuscolo */
                        n = strlen(messaggio);  /* ricavo la lunghezza del messaggio con gli spazi */

                        elimina_spazi(messaggio, messaggio_senza_spazi, n);   /* elimino gli spazi dal messaggio
                                                                               * iniziale */
                        n = strlen(messaggio_senza_spazi);  /* aggiorno la lunghezza della stringa senza spazi! */

                        printf("Messaggio senza spazi: %s\n", messaggio_senza_spazi);

                        separa(messaggio_senza_spazi, messaggio_X, n);  /* separo in coppie il messaggio per verificare
                                                                         * coppie uguali */
                        n = strlen(messaggio_X);      /* aggiorno la dimensione della stringa contenente il messaggio
                                                       * con le X */

                        /*
                         * stampo il messsaggio modificato con l'aggiunta delle X tra le coppie risultate
                         * uguali
                         */
                        printf
                        (
                              "Messaggio ottenuto inserendo le X tra le coppie adiacenti uguali : \n%s\n",
                              messaggio_X
                        );

                        codifica(messaggio_X, matrice_di_sostituzione, messaggio_cifrato, n);   /* codifico la stringa
                                                                                                 * senza spazi */

                        printf("Messaggio codificato contenente l'eventuale X tra le coppie risultate uguali : \n%s\n", messaggio_cifrato);
                        n = strlen(messaggio_cifrato);      /* aggiorno la dimensione */
                        
                        decodifica(messaggio_cifrato, matrice_di_sostituzione, messaggio_decodificato, n);  /* decodifico
                                                                                                             * il
                                                                                                             * messaggio
                                                                                                             * utilizzando
                                                                                                             * la
                                                                                                             * matrice
                                                                                                             * di
                                                                                                             * sostituzione
                                                                                                             * statica
                                                                                                             * */

                        n = strlen(messaggio_decodificato); /* aggiorno la dimensione della stringa ottenuta */
                        printf("Messaggio decodificato contenente l'eventuale X tra le coppie risultate uguali : \n%s\n", messaggio_decodificato);  /* la stampo */

                        cerca_x(messaggio_decodificato, n); /* cerco eventuali X aggiunte tra le lettere uguali */
                        elimina_spazi(messaggio_decodificato, messaggio_senza_spazi, n);  /* elimino gli spazi */
                        printf("Messaggio iniziale %s\n", messaggio_senza_spazi);         /* stampo il messaggio
                                                                                           * iniziale */
                  }
                  break;

            case 2:
                  {
                        printf("\n Matrice di sostituzione non Permutata :\n");
                        stampa_matrice(matrice_di_sostituzione);

                        /* genero i numeri casuali per la permutazione della matrice di sostituzione */
                        srand(time(NULL));            /* cambio la scelta del seed per la generazione di numeri
                                                       * pseudocasuali diversi */

                        /* genero numeri casuali uniformemente distribuiti */
                        do
                        {
                              printf("Quante volte vuoi mescolare la matrice di sostituzione?\n");
                              scanf("%d", &combinazioni);
                        } while(combinazioni < 0);
                        for(i = 0; i < combinazioni; i++)
                        {
                              ncr = rand() % 4;       /* genero il numero di riga del primo simbolo da scambiare (n+1) */
                              ncc = rand() % 8;      /* genero il numero di colonna del primo simbolo da scambiare (n+1) */
                              ncr2 = rand() % 4;      /* genero il numero di riga del secondo simbolo da scambiare (n+1)*/
                              ncc2 = rand() % 8;     /* genero il numero di colonna del secondo simbolo da scambiare (n+1)*/
                              temp = matrice_di_sostituzione[ncr][ncc];
                              matrice_di_sostituzione[ncr][ncc] = matrice_di_sostituzione[ncr2][ncc2];
                              matrice_di_sostituzione[ncr2][ncc2] = temp;
                        }

                        printf("\n");

                        /* stampo la matrice permutata a random */
                        printf("Matrice random ottenuta :\n");
                        stampa_matrice(matrice_di_sostituzione);

                        fflush(stdin);          /* SCARICO IL BUFFER */
                        printf("Inserisci il messaggio da crittografare: \n");
                        gets(messaggio);        /* prendo il messaggio in input con gli spazi */

                        strupr(messaggio);      /* funzione per la conversione di stringhe da minuscolo a Maiuscolo */
                        n = strlen(messaggio);  /* ricavo la lunghezza del messaggio con gli spazi */

                        elimina_spazi(messaggio, messaggio_senza_spazi, n);   /* elimino gli spazi dal messaggio
                                                                               * iniziale */
                        n = strlen(messaggio_senza_spazi);  /* aggiorno la lunghezza della stringa senza spazi! */

                        printf("Messaggio senza spazi: %s\n", messaggio_senza_spazi);

                        separa(messaggio_senza_spazi, messaggio_X, n);  /* separo in coppie il messaggio per verificare
                                                                         * coppie uguali */
                        n = strlen(messaggio_X);      /* aggiorno la dimensione della stringa contenente il messaggio
                                                       * con le X */

                        /*
                         * stampo il messsaggio modificato con l'aggiunta delle X tra le coppie risultate
                         * uguali
                         */
                        printf
                        (
                              "Messaggio ottenuto inserendo le X tra le coppie adiacenti uguali : \n%s\n",
                              messaggio_X
                        );

                        codifica(messaggio_X, matrice_di_sostituzione, messaggio_cifrato, n);   /* codifico la stringa
                                                                                                 * senza spazi */

                        printf("Messaggio codificato : %s\n", messaggio_cifrato);
                        n = strlen(messaggio_cifrato);      /* aggiorno la dimensione */

                        /* decodifico il messaggio utilizzando la matrice di sostituzione statica*/
                        decodifica(messaggio_cifrato, matrice_di_sostituzione, messaggio_decodificato, n);  

                        n = strlen(messaggio_decodificato); /* aggiorno la dimensione della stringa ottenuta */
                        printf("Messaggio decodificato : %s\n", messaggio_decodificato);  /* la stampo */

                        cerca_x(messaggio_decodificato, n); /* cerco eventuali X aggiunte tra le lettere uguali */
                        elimina_spazi(messaggio_decodificato, messaggio_senza_spazi, n);  /* elimino gli spazi */
                        printf("MESSAGGIO iniziale %s\n", messaggio_senza_spazi);         /* stampo il messaggio
                                                                                           * iniziale */
                  }
                  break;

            default:
                  break;
            }

            
      } while(scelta < 1 || scelta > 3);
      system("PAUSE");
      return EXIT_SUCCESS;
}
