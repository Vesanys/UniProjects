typedef struct Archivio
{
	char	titolo[30];
	char	nome_autore[30];
	int		codice[10];
	float	prezzo;
	int		flag;
} disco;

void	carica(disco *, const int);
void	stampa(disco *, const int);
int		massimo(disco *, const int);
void	stampa_con_flag(disco *, const int);
void    ricerca_sequenziale(disco *,int,int *,char*,disco *);
