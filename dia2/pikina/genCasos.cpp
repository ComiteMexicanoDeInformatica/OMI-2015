#include <bits/stdc++.h>

using namespace std;

const int A_i = 1000000;
const int N = 1000000;
const int K = 1000000000;

int main(){
	freopen("Nmenor1e6.caso5.in", "w", stdout);
	
	srand(time(NULL));
	int n = N; // - rand() % N + 1;
	int k = K; // - rand() % K + 1;
	int m = A_i; //rand() % (A_i + 1);
	cout << n << " " << k << endl;
	for(int i = 0; i < n; i++){
		int a;
		if(rand() & 1)
			a = m - rand() % (A_i + 1);
		else a = rand() % (A_i + 1);
		if(i != 0)
			cout << " ";
		cout << a;
	}
	cout << endl;
	return 0;
}