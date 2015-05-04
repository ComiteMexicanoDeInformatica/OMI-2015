#include <stdio.h>
#define MAXN 1002

int mapa[MAXN][MAXN];
int suma[MAXN][MAXN];

int n, T;

inline int min(int a, int b)
{
	if( a < b )
		return a;
	return b;
}

inline int max(int a, int b)
{
	if( a > b )
		return a;
	return b;
}

int sumaCuadro(int i, int j, int size)
{
	if(size < 1)
		return 0;
	return suma[i+size-1][j+size-1] - suma[i+size-1][j-size] - suma[i-size][j+size-1] + suma[i-size][j-size];
}

int maximoCentroBlanco(int i, int j)
{
	int k=0;
	int cActual = 0;
	int tope = min(n-max(i,j)+1, min(i,j));

	while(cActual <= T && k + 2 <= tope)
	{
		k+=2;
		cActual += sumaCuadro(i,j,k) - sumaCuadro(i,j,k-1);
	}

	if( cActual > T )
		k-=2;

	return k;
}

int maximoCentroNegro(int i, int j)
{
	int k=-1;
	int cActual = 0;
	int tope = min(n-max(i,j)+1, min(i,j));

	while(cActual <= T && k + 2 <= tope)
	{
		k+=2;
		cActual += sumaCuadro(i,j,k) - sumaCuadro(i,j,k-1);
	}

	if( cActual > T)
		k -= 2;

	return k;
}

int convertir(int ancho)
{                       
	return ancho * 2 - 1;
	if(ancho & 1)
	{
		int acumulado = 1;
		for(int i=3; i<=ancho; i+=2)
			acumulado += (i-1)*8;
		return acumulado;
	}
	else
	{
		int acumulado = 0;
		for(int i=2; i<= ancho; i+=2)
			acumulado += (i-1)*8;
		return acumulado;
	}
}

int main()
{
	int maximo = 0;
	scanf("%d %d", &n, &T);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d", &mapa[i][j]);
			suma[i][j] = suma[i][j-1] + suma[i-1][j] - suma[i-1][j-1] + mapa[i][j];
		}
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			//maximo = max(maximoCentroNegro(i, j), maximoCentroBlanco(i, j));
			//printf("%d ", maximo);
			maximo = max(maximo, max(maximoCentroNegro(i, j), maximoCentroBlanco(i, j)));
		}
		//printf("\n");
	}
	printf("%d\n", convertir(maximo));

	return 0;
}

