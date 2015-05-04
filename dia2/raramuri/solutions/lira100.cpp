#include <stdio.h>
#define MAXN 1002

int mapa[MAXN][MAXN];
int suma[MAXN][MAXN];
int dA[MAXN][MAXN];
int dB[MAXN][MAXN];

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


int costoNegro(int i, int j, int size)
{
	if(size < 1)
		return 0;
	return dA[i+size][j+size] + 2*dA[i][j] + dA[i-size][j-size] -
			 (dB[i+size][j-size] + 2*dB[i][j] + dB[i-size][j+size]);
}

int costoBlanco(int i, int j, int size)
{
	if(size < 2)
		return 0;
	return dA[i+size][j+size] - 2*dA[i][j] + dA[i-size][j-size] -
			 (dB[i+size][j-size] - 2*dB[i][j] + dB[i-size][j+size]);
}

int maximoCentroBlanco(int i, int j)
{
	int ini, fin, mid;

	ini = 0;
	fin = min(n-max(i,j)+1, min(i,j))/2;

	while(ini < fin)
	{
		mid = (ini + fin + 1) / 2;
		if(costoBlanco(i,j,mid*2) <= T)
			ini = mid;
		else
			fin = mid - 1;
	}

	return ini*2;
}

int maximoCentroNegro(int i, int j)
{

	int ini, fin, mid;

	ini = 0;
	fin = (min(n-max(i,j)+1, min(i,j))+1)/2;
	
	while(ini < fin)
	{
		mid = (ini + fin + 1) / 2;
		if(costoNegro(i,j,mid*2 - 1) <= T)
			ini = mid;
		else
			fin = mid - 1;
	}

	return ini*2-1;
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
			dA[i+1][j+1] = suma[i][j] - dA[i][j];
		}
	}

	for(int i=n; i>=0; i--)
	{
		for(int j=1; j<=n; j++)
		{
			dB[i][j+1] = suma[i][j] - dB[i+1][j];
		}
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			maximo = max(maximo, max(maximoCentroNegro(i, j), maximoCentroBlanco(i, j)));
		}
	}
	printf("%d\n", convertir(maximo));

	return 0;
}
