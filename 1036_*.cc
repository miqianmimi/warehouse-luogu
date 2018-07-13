#include <cstdio>
bool isprime(int sum) {
  for (int i = 2; i * i <= sum; i++)
    if (sum % i == 0) return false;
  return true;
}
int n, k, a[20];
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int S = (1 << n);
  int ans = 0;
  for (int i = 0; i < S; i++) {
    int sum, c = __builtin_popcount(i);
    if (c != k) continue;
    sum = 0;
    for (int j = 0; j < n; j++) sum += (i >> j & 1) * a[j];
    if (isprime(sum)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
