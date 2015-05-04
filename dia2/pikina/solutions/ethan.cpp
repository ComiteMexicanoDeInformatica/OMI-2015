#include <stdio.h>
using namespace std;
 
const int kMaxN = 1000002;
int sort[kMaxN], bucket[kMaxN];
 
int main() {
  int n, k, a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a), ++bucket[a];
  for (int i = kMaxN - 1, j = 0; i >= 0; --i)
    while (bucket[i]--) sort[j++] = i;
  
  int max_rep = 0, number;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && k - sort[i] + sort[j] >= 0) k -= sort[i] - sort[j++];
    if (j - i >= max_rep) max_rep = j - i, number = sort[i];
    k += (sort[i] - sort[i + 1]) * (j - i - 1);
  }
  printf("%d %d\n", max_rep, number);
  return 0;
}