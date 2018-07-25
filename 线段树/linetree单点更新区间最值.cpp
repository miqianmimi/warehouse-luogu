#include<stdio.h>
#include<string.h>
//单点更新，
// sum[]为线段树，需要开辟四倍的元素数量的空间。
// build()为建树操作
// update()为更新操作
// query()为查询操作
//时间复杂度 O(nlogn)
// build(1, n); 建立一个叶子节点为n个的线段树
const int maxn = 2005 + 5;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
int sum[maxn << 2];  //*4 求和操作
void pushup(int rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt = 1) {
  if (l == r) {
    sum[rt] = 0;
    return;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  pushup(rt);
}
// update(pos, val, 1, n); 更新树中下标为pos的叶子节点值增加val
void update(int pos, int val, int l, int r, int rt = 1) {  // +c
  if (l == r) {
    sum[rt] += val;
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m)
    update(pos, val, lson);
  else
    update(pos, val, rson);
  pushup(rt);
}
// query(l, r, 1, n); 查询[l ,r]区间值之和
int query(int L, int R, int l, int r, int rt = 1) {
  if (L <= l && r <= R) return sum[rt];
  int m = (l + r) >> 1;
  int res = 0;
  if (L <= m) res += query(L, R, lson);
  if (R > m) res += query(L, R, rson);
}
