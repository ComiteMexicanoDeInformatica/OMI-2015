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
ll _arregloSumaDesgaste[MAX_FILAS*MAX_COLUMNAS];

int* Desgaste[MAX_FILAS];
ll* TablaSumaDesgaste[MAX_FILAS];

void inicializaTablas(){
	for(int i=0;i<MAX_FILAS;i++){
		Desgaste[i]=&_arregloDesgaste[i*MAX_COLUMNAS];
		TablaSumaDesgaste[i]=&_arregloSumaDesgaste[i*MAX_COLUMNAS];
	}
}

struct Rectangulo{
	int fila1;
	int col1;
	int fila2;
	int col2;
};

ll obtenSumaDeTablaEnRectangulo(ll** Tabla, Rectangulo &rect){
	ll a=0, b=0, c=0, d=0;
	a=Tabla[rect.fila2][rect.col2];
	if(rect.fila1>0){
		b=Tabla[rect.fila1-1][rect.col2];
		if(rect.col1>0){
			c=Tabla[rect.fila1-1][rect.col1-1];
		}
	}
	if(rect.col1>0){
		d=Tabla[rect.fila2][rect.col1-1];
	}	
	return a-b-d+c;
}

ll obtenSumaDesgasteEnRectangulo(Rectangulo rect){
	ll ret=obtenSumaDeTablaEnRectangulo(TablaSumaDesgaste, rect);
	return ret;
}

void calculaTablaSumaDesgaste(){
	for(int i=0;i<TotalFilas;i++){
		for(int k=0;k<TotalColumnas;k++){
			ll sumArriba=0, sumIzq=0, sumDiag=0;
			if(i>0){
				sumArriba=TablaSumaDesgaste[i-1][k];
			}
			if(k>0){
				sumIzq=TablaSumaDesgaste[i][k-1];
			}
			if(i>0 && k>0){
				sumDiag=TablaSumaDesgaste[i-1][k-1];
			}
			TablaSumaDesgaste[i][k]=Desgaste[i][k];
			TablaSumaDesgaste[i][k]+=sumIzq+sumArriba-sumDiag;
		}
	}
}
int obtenMaximoNegroEnPosSemiBrute(int fila, int columna){
	int tintaRestante=Tinta;
	int res=0;
	int next=0;
	for(int lado=0; tintaRestante>0; lado+=2){
		if(lado==0){
			tintaRestante-=Desgaste[fila][columna];
			next++;
		}else{
			if(fila-lado>=0 && columna-lado>=0 && fila+lado<TotalFilas && columna+lado<TotalColumnas){
				Rectangulo rect1, rect2, rect3, rect4;
				rect1.fila1=fila-lado;
				rect1.fila2=fila-lado;
				rect1.col1=columna-lado;
				rect1.col2=columna+lado;
				rect2.fila1=fila+lado;
				rect2.fila2=fila+lado;
				rect2.col1=columna-lado;
				rect2.col2=columna+lado;
				rect3.fila1=fila-lado+1;
				rect3.fila2=fila+lado-1;
				rect3.col1=columna-lado;
				rect3.col2=columna-lado;
				rect4.fila1=fila-lado+1;
				rect4.fila2=fila+lado-1;
				rect4.col1=columna+lado;
				rect4.col2=columna+lado;
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect1);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect2);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect3);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect4);
				next+=2*(2*lado+1)+2*(2*lado-1);
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

int obtenMaximoBlancoEnPosSemiBrute(int fila, int columna){
	int tintaRestante=Tinta;
	int res=0;
	int next=0;
	for(int lado=1; tintaRestante>0; lado+=2){
			if(fila-lado>=0 && columna-lado>=0 && fila+lado<TotalFilas && columna+lado<TotalColumnas){
				Rectangulo rect1, rect2, rect3, rect4;
				rect1.fila1=fila-lado;
				rect1.fila2=fila-lado;
				rect1.col1=columna-lado;
				rect1.col2=columna+lado;
				rect2.fila1=fila+lado;
				rect2.fila2=fila+lado;
				rect2.col1=columna-lado;
				rect2.col2=columna+lado;
				rect3.fila1=fila-lado+1;
				rect3.fila2=fila+lado-1;
				rect3.col1=columna-lado;
				rect3.col2=columna-lado;
				rect4.fila1=fila-lado+1;
				rect4.fila2=fila+lado-1;
				rect4.col1=columna+lado;
				rect4.col2=columna+lado;
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect1);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect2);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect3);
				tintaRestante-=obtenSumaDesgasteEnRectangulo(rect4);
				next+=2*(2*lado+1)+2*(2*lado-1);

			}else{
				break;
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
			res=obtenMaximoNegroEnPosSemiBrute(i, k);			
			if(res>maximo){
				maximo=res;
			}
			res=obtenMaximoBlancoEnPosSemiBrute(i, k);
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
	calculaTablaSumaDesgaste();
	ll res=buscaOptimo();
	cout << res << endl;
	return 0;
}
