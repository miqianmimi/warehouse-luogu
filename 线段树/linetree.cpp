#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int a[500000 * 4];
int sum[500000 * 4];
int T, n, b, c, ans;
char s[20];

int build(int l, int r, int o)  // l左，r右，o节点
{
  if (l == r) return sum[o] = a[l] else {
      int mid = l + (r - l) / 2;
      return sum[o] = build(1, mid, 2 * o) + build(mid + 1, r, 2 * o + 1)
    }
}
void query(int l, int r, int o)  // b,c是要求和的区间
{
  if (b <= l && c >= r)
    ans += sum[o];
  else {
    int mid = l + (r - l) / 2;
    if (b <= mid) query(l, mid, o * 2);
    if (c > mid) query(mid + 1, r, o * 2 + 1);
  }
}
void add(int l, int r, int o) {
  sum[o] += c;
  if (l == r)
    return;
  else {
    int mid = l + (r - l) / 2;
    if (b <= mid)
      add(l, mid, o * 2);
    else
      add(mid + 1, r, o * 2 + 1);
  }
}
int main() {
  int ca = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("Case %d:\n", ca++);
    build(1, n, 1);
    while (scanf("%s", s)) {
      if (s[0] == 'E') break;
      if (s[0] == 'A') {
        scanf("%d%d", &b, &c);
        add(1, n, 1);
      }
      if (s[0] == 'S') {
        scanf("%d%d", &b, &c);
        c = -c;
        add(1, n, 1);
      }
      if (s[0] == 'Q') {
        ans = 0;
        scanf("%d%d", &b, &c);
        query(1, n, 1);
        printf("%d\n", ans);
      }
    }
  }
}