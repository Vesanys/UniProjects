#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"prototipi.h"// con questa istruzione includo i prototipi che mi serviranno in questo file.c


/*
 =======================================================================================================================
 Procedura per la ricerca delle X inserite tra le coppie Uguali (la chiamerò durante la decodifica)
 =======================================================================================================================
 */

void cerca_x(char *messaggio, int n)
{
	/*~~*/
	int i;
	/*~~*/

	for(i = 0; i < n; i++)
	{
		if(messaggio[i] == 'X') messaggio[i] = ' ';// se la lettera è una X allora la sostituisco con uno spazio che dopo verrà eliminato
	}
}

/*
 =======================================================================================================================
 Procedura di stampa della matrice di sostituzione
 =======================================================================================================================
 */
void stampa_matrice(char matrice[][9])
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 8; j++)
		{
			printf(" %c", matrice[i][j]);
			printf(",");
		}

		printf("\n");
	}
}

/*
 =======================================================================================================================
 Procedura per eliminare gli spazi nella stringa(IN: messaggio da elaborare,lunghezza, OUT: stringa senza spazi)
 =======================================================================================================================
 */
void elimina_spazi(char *messaggio, char *temp, int n)
{
	/*~~~~~~~~~*/
	int i, k = 0;
	/*~~~~~~~~~*/

	for(i = 0; i < n; i++)
	{
          // nel codice ASCII le lettere maiuscole iniziano da 65 e terminano a 90 estremi inclusi
		if(messaggio[i] >= 65 && messaggio[i] <= 90)//se è una lettera quella considerata allora la copio altrimenti no (riferito agli spazi)
		{
			temp[k++] = messaggio[i];
			
		}
	}

}

/*
 =======================================================================================================================
 Procedura di decodifica(IN: messaggio da decodificare,lunghezza OUT: messaggio decodificato)
 =======================================================================================================================
 */
 
 //in questa procedura i parametri formali sono il messaggio da decodificare, la matrice di sostituzione a cui facciamo riferimento, messaggio decodificato (in-out) poiche conterrà il messaggio decodificato in out, e la lunghezza effettiva del messaggio da decodificare
void decodifica(char *messaggio, char matrice[][9], char *messaggio_decodificato, int l)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int i, indice = 0, indice_riga_seconda_lettera = 0, indice_colonna_seconda_lettera = 0, ind_r_prima_lettera = 0,
		ind_c_prima_lettera = 0, p, s = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 0; i < l; i += 2)
	{
          // controllo se l'i-esimo carattere confrontato è uguale a '*' che utilizzo per indicare che il carattere successivo sarà \0
		if(messaggio[i] == '*')
			messaggio_decodificato[s++] = '\0';
		else
		{
            //altrimenti chiamo le procedure per trovare le varie coppie all'interno della matrice di sostituzione 
			cerca_lettera(messaggio[i], matrice, &ind_r_prima_lettera, &ind_c_prima_lettera);
			cerca_lettera(messaggio[i + 1], matrice, &indice_riga_seconda_lettera, &indice_colonna_seconda_lettera);
			
			//a questo punto ho ottenuto un indice di riga e uno di colonna ceh mi indicano la posizione delle lettere cercate e le confronto

			if(ind_r_prima_lettera == indice_riga_seconda_lettera)//se l indice delle righe della coppia di lettere analizzata sono uguali
			{
                                   //controllo se l indice di colonna delle lettere esaminate è 0 se questo è vero sposto l indice all ultima colonna(9) cosi da rendere la matrice CIRCOLARE
				if(indice_colonna_seconda_lettera == 0)
					indice_colonna_seconda_lettera = 8;
				else if(ind_c_prima_lettera == 0)
					ind_c_prima_lettera = 8;
					
              //ora la prima e la seconda lettera codificata saranno uguali all elemento a sinistra (in codifica era quello a DESTRA)
				messaggio_decodificato[s++] = matrice[ind_r_prima_lettera][ind_c_prima_lettera - 1];
                messaggio_decodificato[s++] = matrice[ind_r_prima_lettera][indice_colonna_seconda_lettera - 1];
			}
			//altrimenti confronto gli indici di colonna, se sono uguali
			else if(ind_c_prima_lettera == indice_colonna_seconda_lettera)
			{
                 //controllo se ci troviamo nella 1 riga (0) allora sposto l indice sulla 3 riga rendendo la matrice CIRCOLARE
				if(indice_riga_seconda_lettera == 0)
					indice_riga_seconda_lettera = 4;
				else if(ind_r_prima_lettera == 0)
					ind_r_prima_lettera = 4;
				
				//ora le 2 lettere decodificate saranno uguali all elemento sopra (in codifica era quello in BASSO)
                messaggio_decodificato[s++] = matrice[ind_r_prima_lettera - 1][ind_c_prima_lettera];
                messaggio_decodificato[s++] = matrice[indice_riga_seconda_lettera - 1][ind_c_prima_lettera];
			}
			else
			{   //altrimenti significa ceh hanno diversi indici di riga e colonna e quindi la lettera decodificata avrà riga della prima lettera e colonna della seconda
			   // la seconda lettera avra riga della seconda lettera e colonna della prima
				messaggio_decodificato[s++] = matrice[ind_r_prima_lettera][indice_colonna_seconda_lettera];
                messaggio_decodificato[s++] = matrice[indice_riga_seconda_lettera][ind_c_prima_lettera];
			}
		}
	}
}

/*
 =======================================================================================================================
 Procedura di ricerca di una lettera (sequenziale) 
 INPUT: matrice di sostituzione, la chiave (lettera) da ricercare
 OUTPUT: indice riga e indice colonna (in-out)
        
        funzionamento:
                      confronto la chiave con ogni simbolo presente nella matrice di sostituzione
                      finche non lo trovo e restituisce l indice di riga e di colonna trovati
 =======================================================================================================================
 */
void cerca_lettera(char lettera, char matrice[][9], int *indice_riga, int *indice_colonna)
{
	/*~~~~~*/
	int i, j;
	/*~~~~~*/

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(matrice[i][j] == lettera)
			{
				*indice_riga = i;
				*indice_colonna = j;
			}
		}
	}
}

/*
 =======================================================================================================================
 Procedura di Codifica
 INPUT:
       messaggio da codificare, matrice di sostituzione, lunghezza
 OUTPUT: messaggio cifrato(in-out)
 
 funzionamento:
               prendo in input il messaggio da codificare ricerco le 2 lettere che formano la coppia all interno della
               matrice di sostituzione utilizzata, ricavo l indice di riga e di colonna della lettera trovata.
               Confronto i due indici di riga e\o colonna trovati e in base a se sono uguali o diversi codifico le lettere.
               
 =======================================================================================================================
 */
void codifica(char *messaggio, char matrice[][9], char *messaggio_cifrato, int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int i, indice = 0, indice_riga_seconda_lettera = 0, indice_colonna_seconda_lettera = 0, ind_r_prima_lettera = 0,
		ind_c_prima_lettera = 0, s = 0;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 0; i < n; i += 2)
	{
          //controllo che la lettera finale nel caso in cui sia Dispari non venga confrontata con una posizione non disponibile(\0)
		if(messaggio[i + 1] == '\0')//se si verifica allora sostituisco al carattere s-esimo il simbolo '*' che simboleggia il confronto con \0
			messaggio_cifrato[s++] = '*';
		else
		{
            //altrimenti richiamo la procedura per ricercare le lettere all interno della matrice di sostituzione
			cerca_lettera(messaggio[i], matrice, &ind_r_prima_lettera, &ind_c_prima_lettera);
            cerca_lettera(messaggio[i + 1], matrice, &indice_riga_seconda_lettera, &indice_colonna_seconda_lettera);


			if(ind_r_prima_lettera == indice_riga_seconda_lettera)	/* controllo se l indice della prima lettera e'
																	 * uguale all indice della seconda lettera  se questo è vero*/
			{

				/* effettuo i controlli per rendere la matrice circolare */
				if(indice_colonna_seconda_lettera == 7)
					indice_colonna_seconda_lettera = -1;
				else if(ind_c_prima_lettera == 7)
					ind_c_prima_lettera = -1;
				
				//l's-esima lettera del messaggio cifrato ora sara' uguale al simbolo alla DESTRA 
                messaggio_cifrato[s++] = matrice[ind_r_prima_lettera][ind_c_prima_lettera + 1];
                messaggio_cifrato[s++] = matrice[ind_r_prima_lettera][indice_colonna_seconda_lettera + 1];
			}
			else if(ind_c_prima_lettera == indice_colonna_seconda_lettera)//controllo se gli indici di colonna delle lettere analizzate sono uguali e se vero
			{
                 //controllo se siamo sull ultima riga, e se vero faccio in modo che la matrice risulti circolare ovvero che si sposti alla 1 riga (0)
				if(indice_riga_seconda_lettera == 3)
					indice_riga_seconda_lettera = -1;
				else if(ind_r_prima_lettera == 3)
					ind_r_prima_lettera = -1;
				
				//l's-esima lettera del messaggio cifrato sara uguale alla lettera in BASSO
                messaggio_cifrato[s++] = matrice[ind_r_prima_lettera + 1][ind_c_prima_lettera];
                messaggio_cifrato[s++] = matrice[indice_riga_seconda_lettera + 1][ind_c_prima_lettera];
			}
			else
			{  //se i casi precedenti risultano negativi dignifica che gli indici di riga e colonna sono diversi e quindi
			   //l's-esimo carattere cifrato sara' uguale allo stesso indice di riga ma colonna dell altra lettera
				messaggio_cifrato[s++] = matrice[ind_r_prima_lettera][indice_colonna_seconda_lettera];
                messaggio_cifrato[s++] = matrice[indice_riga_seconda_lettera][ind_c_prima_lettera];
			}
		}
	}
}

/*
 =======================================================================================================================
 Procedura di separazione e inserimento della X tra le coppie risultanti Uguali
 
 INPUT:
       messaggio da analizzare, lunghezza
 OUTPUT: 
         stringa contenente le X (in-out)
 funzionamento:
               prendo il messaggio da analizzare in input 
               con un for analizzo le coppie di caratteri se sono diversi li copio nella stringa di output
               altrimenti copio la prima lettera e nella seconda inserisco una X, e cosi vado avanti con il for
               utilizzo 2 indici differenti per le due stringhe (N.B. k++ prima prende il contenuto dell indice K poi incrementa)
 =======================================================================================================================
 */
void separa(char *messaggio, char *stringa, int n)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~*/
	int		cont = 0, k = 0, i;
	char	temp;
	/*~~~~~~~~~~~~~~~~~~~~~~~*/

	for(i = 0; i < n; i++)
	{
		if(messaggio[i] != messaggio[i + 1])
		{
			stringa[k++] = messaggio[i];
			stringa[k++] = messaggio[i + 1];
			i++;
		}
		else
		{
			stringa[k++] = messaggio[i];
			stringa[k++] = 'X';
		}
	}
}
