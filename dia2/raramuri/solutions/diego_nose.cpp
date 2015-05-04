#include<iostream>
const int MAXN = 1010;
#define fst first
#define snd second
typedef pair<int,int> ii;

int A[MAXN][MAXN];
int B[MAXN][MAXN]
int lel;
int diagP[MAXN][MAXN];
int diagS[MAXN][MAXN];
int S[MAXN][MAXN];
int N;


int calcularA(ii A,int k){
    return S[A.fst+k-1][A.snd+k-1]+S[A.fst-1][A.snd-1]-S[A.fst+k-1][A.snd-1]-S[A.fst-1][A.snd+k-1];
}

int cuadroCalc(ii A,int l){
    int m = 0;
    for(int j = l,i=0; j>=1;j-=2,i++){
        m+=calcularA(ii(i+A.fst,i+A.snd),j);
    }
    return m;
}

int calcularDiagP(ii A,int k){
    return diagP[A.fst][A.snd]-diagP[A.fst-k][A.snd-k];
}

int calcularDiagS(ii A,int k){
    return diagS[A.fst][A.snd]-diagS[A.fst-k][A.snd+k];
}

int calcularColumna(ii A,int k){
    return S[A.fst+k-1][A.snd]+S[A.fst-1][A.snd-1]-S[A.fst+k-1][A.snd-1]-S[A.fst-1][A.snd];
}

int dfDer(ii A,int k,int df){
    int u = 2*k-1;
    int l = 4*k-3;
    ii C(A.fst+u-1,A.snd+u);
    ii D(A.fst,A.snd+l+1);

    df += calcularColumna(A,l) - calcularDiagP(C,u) + calcularDiagS(C,-u+1);
    df += calcularColumna(D,l) + calcularDiagP(C,-u+1) - calcularDiagS(C,u);
    return df;
}

int dfAba(ii A,int k,int df){
    int u = 2*k-1;
    int l = 4*k-3;
    ii B(A.fst+u-1,A.snd+u-1);
    ii C(A.fst+u-1,A.snd+u);

    df += calcularDiagP(B,u) + calcularDiagS(C,-u);
    df += -calcularDiagP(B,-u) - calcularDiagS(C,u);
    return df;
}

bool fila(int i, int k, int D, int m, int df){
    for(int mp=m,dfp = df,j=1 ; j<=N ; mp=mp + dfp , dfp = dfDer(ii(i,j),k,dfp) , j++){
        if(mp <= D) return true;
    }
    return false;
}

bool posible(int k,int D) {
    int l = k*4-3;
    int m=0,dfD=0,dfA=0 , np = N-1;
    m = cuadroCalc(ii(1,1),l);
    m2 = cuadroCalc(ii(1,2),l);
    df = m2 - m;
    for(int mi = m, dfi = df, i = 1 ; i<=N; mi += dfi, dfi = dfAba(ii(i,1),k,dfi), i++ ){
        if( fila(i,k,D,mi,dfi) ){
	    return true;
	}    
    }
    return false;
}



int main(){
    int D;
    cin >> N >> D;
    for(int i = 1; i <= N ; i++) {
        for(int j = 1; j <= N ; j++) {
	    cin >> A[i][j];
	}
    }
    for(int i = 1; i <= N ; i++) {
        for(int j = 1; j <= N ; j++) {
	    S[i][j] = A[i][j] + S[i-1][j];
	    diagP[i][j] = A[i][j] + diagP[i-1][j-1];
	    diagS[i][j] = A[i][j] + diagS[i-1][j+1];
	}
    }
    for(int j = 1 ; j <= N ; j++){
        for(int i = 1 ; i<= N; i++){
	    S[i][j] += S[i][j-1];
	}
    }
    a=1,b=(N+3)/4+1,m;
    while(a != b - 1){
       m = (a+b)/2;
       if(posible(m,D)){
           a = m;
       } else{
           b = m; 
       }
    s
    cout << m*2-1;
}
