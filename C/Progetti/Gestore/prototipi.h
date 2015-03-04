 /*
 =======================================================================================================================
    Dichiarazione della struttura dati e dei prototipi delle funzioni
 =======================================================================================================================
 */
typedef struct Gestore
{
	double	id_chiamante;
	double	id_ricevente;
	float	durata;
} chiamata;
void	carica(chiamata *, const int);
void	stampa(chiamata *, const int);
int		massimo(chiamata *, const int);
void	ricerca_sequenziale(chiamata *, int, int *, double, chiamata *);
float	totale_costo_chiamate(chiamata *, int, float costo);
