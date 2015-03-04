#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int dimensione();//protitipo chiamata alla funzione della dimensione
void carica(int *,int); //prototipo del caricamento del vettore
void stampa(int , const int );
void ordina(int *, const int );
void max_val_ind(int *, int ,int *, int *);
void scambiare(int *,int *);
int dimensione()
{
    int nn;
    do{
              printf("Inserisci dimensione \n");
              scanf("%d", &nn);
              }while(nn<0 || nn>MAX);
return nn;
}
void carica(int *v,int nn)
{
     for(int i=0;i<nn;i++){
                             printf("inserisci l elemento [%d] ", i+1);
                             scanf("%d", &v[i]);
                             }
} 
// Funzione per la stampa degli elementi dell'elenco
void stampa(int *Vet, const int n) {

	for(int i=0;i<n;i++) {
		printf("\n V[%d]= %d",i+1,Vet[i]);
	}
}

//ordinamento per selezione di massimo
void ordina(int *v,const int n)
{  
     int i,indice_max,max_array;
     
   for(i=n-1;i>0;i--){
                      max_val_ind(&v[0],i+1,&max_array,&indice_max);
                      scambiare(&v[i],&v[indice_max]);
//in questo caso l indice del massimo nella porzione non ha bisogno di essere spaziato a differenza della selezione del minimo 
                      }
}
void max_val_ind(int *v, int n,int *max_array, int *i_max)
{
     int i;
     *max_array =v[0];
     *i_max =0;
     for (i=1;i<n;i++)if(v[i] > *max_array) {
                                                *max_array =v[i];
                                                *i_max =i;
                                                }
}
void scambiare(int *v1,int *v2)
{
     int temp;
     temp=*v1;
     *v1 =*v2;
     *v2 =temp;
}

int main()
{
    int v[MAX],n;
    
    n=dimensione();
    carica(v,n);
    printf("Array inserito :\n");
    stampa(v,n);
    ordina(v,n);
    printf("\nArray ordinato per selezione di massimo :\n");
   stampa(v,n);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
