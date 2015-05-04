#include <cstdio>
#include <algorithm>

#define MAXN 1000000

using namespace std;

int N, K, a[MAXN], M = 0, m = 1<<25;

int main(){
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		M = max(M, a[i]);
		m = min(m, a[i]);
	}

	printf("%d\n", M - m);
}
