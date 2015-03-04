Progetto Crittography:

Sviluppare una coppia di algoritmi, implementati come function, per crittografare e decrittografare un
messaggio. L'algoritmo si basa sulla cosiddetta cifratura polialfabetica, che consiste nel trasformare 
il messaggio in un testo di lunghezza maggiore o uguale a quella del messaggio, detto il testo cifrato, 
utilizzando una matrice di caratteri (prefissata), detta matrice di sostituzione. Il messaggio da 
crittografare viene dapprima partizionato le coppie di lettere adiacenti; se in tale partizionamento 
accade che una coppia è formata dalla stessa lettera, allora si inserisce una X tra le due. Per esempio, 
il messaggio : LET US MEET AT NOON viene partizionato in LE TU SM EX ET AT NO ON. Si è inserita una X tra 
le due E, ma non tra le due O, che si trovano in coppie diverse. 
Si consideri la seguente matrice di sostituzione: 
        
        8 J E Q D N 5 O 
        P U 3 A R F L W 
        4 V C 2 T M B I 
        K 7 Z S G X H Y 

Ogni coppia di lettereviene crittografata nel seguente modo: 
     a. se le lettere sono nella stessa riga della matrice di sostituzione, le due lettere da inserire nel 
        testo cifrato saranno le lettere immediatamente a destra nella stessa riga. Ogni riga e' 
        considerata circolare. Per esempio, la coppia TI viene crittografata come M4. 
     b. se le lettere sono nella stessa colonna della matrice di sostituzione, le due lettere da inserire 
        nel testo cifrato saranno le lettere immediatamente sotto nella stessa colonna. Ogni colonna e' 
        considerata circolare. Per esempio, la coppia RG viene crittografata come TD. 
     c. se le lettere appaiono in differenti righe e colonne della matrice di sostituzione, ognuna delle 
        due lettere sara' crittografata con la lettera nella stessa riga ma nella colonna dell'altra 
        lettera. Per esempio, la coppia LE viene crittografata come 35. Il messaggio LET US MEET AT NOON 
        viene quindi crittografato in 35VRX2NZDCR25885. 

Il main legge da tastiera il messaggio da crittografare l'equivalente di LET US MEET AT NOON nell'esempio),
chiama la function di cifratura (passando come parametro il messaggio e la matrice di sostituzione),che 
restituisce il testo cifrato, visualizza il testo cifrato, chiama la function di decifratura, passando 
come parametro il testo cifrato e la matrice di sostituzione, visualizza il messaggio decifrato, che 
deve coincidere con il messaggio di partenza. Usare solo lettere maiuscole. Usare le stringhe per 
rappresentare il messaggio e il testo crittografato e decrittografato. Fare una versione alternativa del 
main, in cui la matrice di sostituzione e' una permutazione casuale della matrice precedente, usando la 
function rand(), il cui prototipo e' in <stdlib.h>, per generare gli interi casuali per lo scambio a 
coppie di elementi della matrice. Si ricorda che, se numero_casuale e' dichiarata di tipo int, allora la 
chiamata numero_casuale=rand()%(n+1); genera un numero casuale intero (distribuzione uniforme) 
nell'insieme (0,1,2,..n). Usare sempre la srand() per rendere automatica la scelta iniziale del seed della
sequenza di numeri casuali. 

Progetto Gestore:

Si vuole simulare  l'archivio  di  chiamate  di  un  gestore telefonico. L'archivio risulta mensile 
(31 giorni). Ogni giorno vengono effettuate al massimo 10 chiamate e il costo al minuto di una chiamata è 
di 10 centesimi. Ogni chiamata è  identificata  dal numero  chiamante,  il numero ricevente e la  durata 
della chiamata. Provvedere  all' implementazione  dell' algoritmo  per  la   simulazione  dell' archivio.  
Permettere,inoltre, all' utente di : 

       *  Inserire una chiamata in un dato giorno 
       *  Dato un numero telefonico visualizzare tutte le chiamate con le relative informazioni in un 
          singolo giorno 
       *  Dato un numero telefonico vedere il costo totale delle chiamate. 
       *  Visualizzare le informazioni relative alla chiamata più costosa. 
       
       
Progetto: Gioco del 7 e Mezzo:

/*
 * Gioco del 7 e Mezzo. Viene richiesto di inserire i nomi dei due giocatori. Dopo
 * aver inserito i nomi dei due giocatori, verrà chiesto il numero di volte
 * che si desidera mischiare il mazzo di carte. Dopo aver mischiato il mazzo di
 * carte, il primo giocatore inizia a giocare con una carta estratta in modo
 * casuale: --> Se il punteggio e' pari a 7 e Mezzo, allora il primo giocatore Ha
 * Vinto la partita. --> Se il punteggio supera 7 e Mezzo, allora il primo giocatore
 * Ha Perso la partita. Il primo giocatore può ora decidere di non richiedere
 * un'alta carta. Nel caso in cui il primo giocatore decida di non richiedere
 * un'altra carta, il turno passa al secondo giocatore. Ora e' il turno del
 * secondo giocatore, il quale inizia a giocare anch'esso con una carta estratta
 * in modo casuale: Il secondo giocatore può ora decidere se richiedere un'alta
 * carta. --> Se il punteggio e' pari a 7 e Mezzo, allora il secondo giocatore Ha
 * Vinto la partita. --> Se il punteggio supera 7 e Mezzo, allora il secondo
 * giocatore Ha Perso la partita. Il secondo giocatore può ora decidere di non
 * richiedere un'alta carta. Nel caso in cui il secondo giocatore decida di non
 * richiedere un'altra carta, il sistema provvede a comparare il punteggio del
 * primo e secondo giocatore, il giocatore cha ha un punteggio più grande e che
 * non supera 7 e Mezzo Vince.
*/

Progetto FiltraggioSuoni:
/*
 * Dati due array monodimensionali x ed y di dimensione 1xn.
 * Ognuno contiene le informazioni relative ad un file sonoro. Si chiede di
 * implementare una funzione che permette di ottenere la mistura dei due segnali
 * secondo la seguente relazione: z[i] = A[0]*x[i]+A[1]*y[i], dove A e un array di
 * dimensioni 1x2 i cui valori sono compresi nell'intervallo [0,1].
 * Successivamente si chiede di implementare il filtraggio della mistura z[i] in
 * modo da ottenere una nuovo suono filtrato y[i] = sommatoria che va da k=0 a 9
 * di C[k]z[i+k]. dove C e un vettore di coefficienti inseriti dall'utente e di
 * dimensione 10. Per ottenere il filtraggio bisogna aggiungere degli zero alla
 * fine della sequenza z[i]. I suoni vengono inizializzati casualmente con valori
 * float nell'intervallo [-10, 10] e i coefficienti vengono inseriti dall'utente.
 * Filtraggio Suoni.
 */

Progetto Gioco del Tennis:

Questo programma simula 100 partite di tennis, ognuna composta da 500 lanci. 
Il campo, il giocatore e la racchetta sono identificati da lettere e simboli 
caricati in una matrice 4 x 5 presente nel file.

Progetto Archivio di Dischi:

Con questo programma si vuole simulare la gestione un negozio di dischi multimendiali,
dando la possibilità di inserire uno o più dischi nell'archivio; ricercare un disco
inserendo il nome dell'autore o del gruppo, ricerca del disco inserendo il prezzo,
ricerca del disco tramite il codice, sapere se un disco è presente o in prestito 
oppure restituire il disco inserendo il codice.
