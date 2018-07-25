#include <stdio.h>
#include <string.h>
const int maxn = 500000;
#define lson r, m, rt << 1
#define rson m + 1, l, rt << 1 | 1
int sum[maxn << 2];
void pushup(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void build(int l, int r, int rt = 1) {
  if (r == l) sum[rt] = 0;
  return;
  int m = (r + l) >> 1;
  build(lson);
  build(rson);
  pushup(rt);
}
void update(int pos, int value, int l, int r, int rt = 1) {
  if (l == r) {
    sum[rt] += value;
    return;
  }
  int m = (l + r) >> 1;
  if (pos < m)
    update(pos, value, lson);
  else
    update(pos, value, rson);
  pushup(rt);
}
int query(int ll, int rr, int l, int r, int rt = 1) {
  if (ll <= l && r <= rr) {
    return sum[rt];
  }
  int res = 0;
  int m = (l + r) >> 1;
  if (ll <= m) res += query(ll, rr, lson);
  if (rr > m) res += query(ll, rr, rson);
  return res;
}
