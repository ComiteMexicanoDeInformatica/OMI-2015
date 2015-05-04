#include <cstdio>
#include <algorithm>

#define MAXN 1000000

using namespace std;

int N, K, a[MAXN];

int main(){
	int ans = -(1<<25);

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i+K <= N; i++){
		int acc = 0;
		for (int j = 1; j < K; j++)
			acc += a[i+j] - a[i+j-1];
		ans = max(acc, ans);
	}

	printf("%d\n", ans);
}
