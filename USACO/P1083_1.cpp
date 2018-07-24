#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define min(a, b) (a < b ? a : b)
const int maxn=1000010;
struct segment {
  int l;
  int r;
  int minn;
  int minus;
} tree[maxn << 2];
int a[maxn], n, m, l, r, s;

void build(int l, int r, int now) {  // l是最小的数，r是最大的数,x是数组
  tree[now].l = l;
  tree[now].r = r;
  if (l == r) {
    tree[now].minn = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1);
  build(mid + 1, r, now << 1 | 1);
  tree[now].minn = min(tree[now << 1].minn, tree[now << 1 | 1].minn);
}
void update(int now) {
  tree[now].minn = min(tree[now].minn,
                       min(tree[now << 1].minn - tree[now << 1].minus,
                           tree[now << 1 | 1].minn - tree[now << 1 | 1].minus));
}
void change(int l, int r, int now, int num) {
  if (tree[now].l == l && tree[now].r == r) {
    tree[now].minus += num;
    return;
  }
  int mid = (tree[now].l + tree[now].r) >> 1;
  if (r <= mid)
    change(l, r, now << 1, num);
  else if (l > mid)
    change(l, r, now << 1 | 1, num);
  else
    change(l, mid, now << 1, num), change(mid + 1, r, now << 1 | 1, num);
  update(now);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &s, &l, &r);
    change(l, r, 1, s);
    if (tree[1].minn - tree[1].minus < 0) {
      printf("-1\n%d", i);
      return 0;
    }
  }
  printf("0");
  return 0;
}