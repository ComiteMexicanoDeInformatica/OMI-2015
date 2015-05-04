#include <stdio.h>
#include <algorithm>
using namespace std;
int numero_casos=20;
#define max_numero 10001
#define max_n 50000
int N[]={2,3,10,50,101,1000,3333,5000,7500,8123,15000,25000,33201,39999,41234,49999,50000,50000,50000,50000};

int tipo[]={0,0,0,0,5,1,2,3,4,6,6,6,6,6,6,2,3,4,6,6};

int data[max_n];
//0
void llena_random(int n){
	int temp_max_numero=max_numero-rand()%100;
	for(int r=0;r<n;r++)
	   data[r]=rand()%temp_max_numero;
}
// 1
void llena_igual(int n){
	for(int r=0;r<n;r++)
	   data[r]=0;
}
//2
void llena_creciente(int n){
	int temp_max_numero=max_numero-rand()%100;
	for(int r=0;r<n;r++)
	   data[r]=r%temp_max_numero;
}
//3
void llena_decreciente(int n){
	for(int r=0;r<n;r++)
	   data[r]=abs(max_numero-1-r)%max_numero;
}
//4
void llena_alternado(int n){
	for(int r=0;r<n;r++)
	{
		if(r%2==0)
		  data[r]=r%max_numero;
		 else
		   data[r]=(n-r)%max_numero;
	}
}
//5
void llena_decreciente_no_uniforme(int n){
	int acumulado=0;
	for(int r=0;r<n;r++){
	   data[r]=(max_numero-1-acumulado+max_n)%max_numero;
	   acumulado+=(rand()%50+50);
	}
}	
//6
void llena_random_inteligente(int n){
	int rango=rand()%1000+2;
	int acumulado=max_numero/2;
	for(int r=0;r<n;r++){
	   data[r]=acumulado;
	   //acumulado=min(max_numero-1,abs(acumulado+rand()%(rango*2)-rango))%max_numero;
	   acumulado=max(max_numero/2- rand()%max_numero/3,min(max_numero/2+ rand()%max_numero/3,abs(acumulado+rand()%(rango*2)-rango)));
	}
}

int main(){
	srand(1);
	for(int caso=0;caso<numero_casos;caso++){
		
		
		if(tipo[caso]==0) llena_random(N[caso]);
		if(tipo[caso]==1) llena_igual(N[caso]);
		if(tipo[caso]==2) llena_creciente(N[caso]);
		if(tipo[caso]==3) llena_decreciente(N[caso]);
		if(tipo[caso]==4) llena_alternado(N[caso]);
		if(tipo[caso]==5) llena_decreciente_no_uniforme(N[caso]);
		if(tipo[caso]==6) llena_random_inteligente(N[caso]);
		
		char path[100];
		sprintf(path,"cases/in%d.in",caso);
		
		FILE *archivo_entrada= fopen(path,"w");
		
		fprintf(archivo_entrada, "%d\n",N[caso]);
		for(int r=0;r<N[caso];r++)
			fprintf(archivo_entrada, "%d ",data[r]);
			
		fclose(archivo_entrada);	
		
		char command[100];
		sprintf(command,"sol.exe < cases/in%d.in > cases/in%d.out",caso,caso);
		system(command);
		
	}

	return 0;

}

