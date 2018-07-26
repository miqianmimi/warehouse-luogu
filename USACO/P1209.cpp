#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int m, s, n;
int a[202];
int f[52];
int interval[202];
int ans;
int main() {
  cin >> m >> s >> n;
  if (m >= n) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
  	cin>>a[i];
  }
  sort(a + 1, a + 1 + n);
  int i = 1;
  while (true) {
    interval[i] = a[i + 1] - a[i]-1;
    //printf("%d : %d\n", i,interval[i]);
    if (i + 1 == n) {
      break;
    }
    i++;
  }
  sort(interval + 1, interval + n);
  ans = a[n] - a[1]+1;
  for (int i = 1; i <= m - 1; i++) {
    ans -= interval[n - i];
  }
  cout << (ans) << endl;
  return 0;
}