/*Sviluppare una function C che, dati come parametri di input un array di int e il suo size,
determina e restituisce come parametri di output l'indice di inizio e la lunghezza della piu
lunga sequenza ordinata (senso crescente) contenuta nell'array.*/
#include <stdlib.h>
#include<stdio.h>
#define MAX 100

int dimensione();
void carica(int *,const int );
void calcola(int *,const int,int *,int *);


int dimensione()
{
	int n;
	do{
		printf("Inserisci la dimensione del vettore\n");
		scanf("%d",&n);
	}while(n<0 || n>MAX);

	return n;
}
void carica(int *v,const int n)
{
	int i;
	for(i=0;i<n;i++){
		                printf("Inserisci il %d elemento ",i+1);
						scanf("%d",&v[i]);
	}

}
void calcola(int *v,const int n,int *i_max,int *max)
{
	int temp=-1,max_temp=1,i;

	for(i=0;i<n-1;i++){
		if(v[i]<v[i+1]){
			             if (temp<0) temp=i;

						 max_temp++;
						 printf("temp %d",temp);
						 system("pause");
		}
		else 
			if (max_temp>*max){
				*max=max_temp;
				*i_max=temp;
		}
			max_temp=1;
			temp=-1;
	}
if (max_temp>*max){
				*max=max_temp;
				*i_max=temp;
		}
}
int main()
{
	int v[MAX];
    int n,max=0,i_max;
	n=dimensione();
    carica(v,n);
	calcola(v,n,&i_max,&max);

	printf("la lunghezza della sequenza piu lunga ordinata in senso crescente e' %d\n",max);
    printf("la sequenza ordinata ha inizio con l elemento di indice %d\n",i_max);


	system("pause");
	return 0;

}
