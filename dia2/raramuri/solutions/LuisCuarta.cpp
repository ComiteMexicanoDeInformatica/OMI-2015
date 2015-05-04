#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;
typedef int64_t ll;

int Tinta;
int TotalFilas;
int TotalColumnas;
const int MAX_FILAS=1000;
const int MAX_COLUMNAS=1000;

int _arregloDesgaste[MAX_FILAS*MAX_COLUMNAS];
int* Desgaste[MAX_FILAS];

void inicializaTablas(){
	for(int i=0;i<MAX_FILAS;i++){
		Desgaste[i]=&_arregloDesgaste[i*MAX_COLUMNAS];
	}
}

int obtenMaximoNegroEnPosBrute(int fila, int columna){
	int tintaRestante=Tinta;
	int res=0;
	int next=0;
	for(int lado=0; tintaRestante>0; lado+=2){
		if(lado==0){
			tintaRestante-=Desgaste[fila][columna];
			next++;
		}else{
			if(fila-lado>=0 && columna-lado>=0 && fila+lado<TotalFilas && columna+lado<TotalColumnas){
				for(int k=columna-lado; k<=columna+lado; k++){
					tintaRestante-=Desgaste[fila-lado][k];
					tintaRestante-=Desgaste[fila+lado][k];
					next+=2;
					if(tintaRestante<0){
						break;
					}
				}
				for(int i=fila-lado+1; i<=fila+lado-1; i++){
					tintaRestante-=Desgaste[i][columna-lado];
					tintaRestante-=Desgaste[i][columna+lado];
					next+=2;
					if(tintaRestante<0){
						break;
					}
				}
			}else{
				break;
			}
		}
		if(tintaRestante>=0){
			res=2*lado+1;
		}
	}
	return res;
}

int obtenMaximoBlancoEnPosBrute(int fila, int columna){
	int tintaRestante=Tinta;
	int res=0;
	int next=0;
	for(int lado=1; tintaRestante>0; lado+=2){
		if(lado==0){
			tintaRestante-=Desgaste[fila][columna];
			next++;
		}else{
			if(fila-lado>=0 && columna-lado>=0 && fila+lado<TotalFilas && columna+lado<TotalColumnas){
				for(int k=columna-lado; k<=columna+lado; k++){
					tintaRestante-=Desgaste[fila-lado][k];
					tintaRestante-=Desgaste[fila+lado][k];
					next+=2;
					if(tintaRestante<0){
						break;
					}
				}
				for(int i=fila-lado+1; i<=fila+lado-1; i++){
					tintaRestante-=Desgaste[i][columna-lado];
					tintaRestante-=Desgaste[i][columna+lado];
					next+=2;
					if(tintaRestante<0){
						break;
					}
				}
			}else{
				break;
			}
		}
		if(tintaRestante>=0){
			res=2*lado+1;
		}
	}
	return res;
}
ll buscaOptimo(){
	ll maximo=0;
	for(int i=0;i<TotalFilas;i++){
		for(int k=0;k<TotalColumnas;k++){
			ll res;
			res=obtenMaximoNegroEnPosBrute(i, k);
			
			if(res>maximo){
				maximo=res;
			}
			res=obtenMaximoBlancoEnPosBrute(i, k);
			if(res>maximo){
				maximo=res;
			}
		}
	}
	return maximo;
}

void leeEntrada(){
	scanf("%d", &TotalFilas);
	TotalColumnas=TotalFilas;
	scanf("%d", &Tinta);
	for(int i=0;i<TotalFilas;i++){
		for(int k=0;k<TotalColumnas;k++){
			scanf("%d", &Desgaste[i][k]);
		}
	}
}

int main(){
	inicializaTablas();
	leeEntrada();
	ll res=buscaOptimo();
	cout << res << endl;
	return 0;
}
