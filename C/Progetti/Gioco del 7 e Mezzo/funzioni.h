/*$T indentinput.h GC 1.140 05/26/11 08:59:30 */

/*
 * Header file ;
 * Dichiarazione di una Struttura (Tipo Struct), essa consente di dichiarare
 * specifici tipi derivati, quindi gestire aggregati di variabili di tipo non
 * omogeneo
 */
typedef enum { denari, bastoni, spade, coppe } Semi;	/* Tipo Enumerativo derivato: Semi */

typedef struct carta
{
	int		valore;
	Semi	seme;
} Carta;			/* Tipo derivato Carta. Poiche' Carta e' adesso un nuovo tipo, pu� essere utilizzato per
					 * dichiarare variabili */

Carta	mia_carta;	/* Dichiarazione di mia_carta al nuovo tipo Carta */

/* Dichiarazione dei Prototipi delle Funzioni e Procedure */
void	mischia(Carta *, int);	/* Prototipo della procedura mischia che consente di mischiare le carte */
void	scambia_carte(Carta *, int, int);	/* Prototipo della procedura scambia_carte che consente di scambiare le
											 * carte */
int		controllo_punteggio(float);			/* Prototipo della funzione controllo_punteggio che consente di controllare
											 * il punteggio dei giocatori */
float	aggiorna_punteggio(Carta, float);	/* Prototipo della funzione aggiorna_punteggio che cosente di aggiornare il
											 * punteggio dei giocatori */
void	stampa_carta(Carta);	/* Prototipo della procedura stampa_carta che consente di visualizzare la carta scelta */
float	gioca(char *, float, Carta *, int *);	/* Prototipo della funzione gioca che consente di controllare il gioco */
int		pesca_carta(int *); /* Prototipo della funzione pesca_carta che consente il controllo delle carte gia' uscite */
