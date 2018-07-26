#include <cstdio>
#include <iostream>  //万能头文件
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node  //虫洞的坐标
{
  int x, y;
} a[21];
int n, ans = 0;
int f[21];
inline int cmp(
    const void *xx,
    const void *yy)  //排序一次，就可以方便的连接虫洞了，pd函数中显示出来
{
  node x = *(node *)xx;
  node y = *(node *)yy;
  if (x.y < y.y) return 1;
  if (x.y == y.y && x.x < y.x) return 1;
  return 0;
}
bool pd(
    int k, int t, int bk,
    int c)  // k表示步数，t表示当前虫洞的编号，bk表示初始虫洞，c表示是否能利用这个虫洞来传送
{
  if (k != 1 && t == bk && c == 0)  //如果陷入循环，就返还可以
  {
    return true;
  }
  if (c == 0)  //如果不可以用虫洞传送，就要步行到下一个
  {
    if (a[t].y == a[t + 1].y)  //如果能走到的话
    {
      return pd(k + 1, t + 1, bk, 1);  //往下深搜，下一个可以传送
    } else
      return false;  //不然就不能陷入循环
  }
  if (c == 1)  //如果可以床送的话
  {
    return pd(k + 1, f[t], bk, 0);  //下一个不能传送
  }
}

void dfs(int k)  // dfs来找出所有的环
{
  if (k == n + 1)  //如果找完了所有的环
  {
    for (int i = 1; i <= n; i++)  //判断一下
    {
      if (pd(1, i, i, 0) == true)  //如果可以
      {
        ans++;
        break;  //记录，并退出
      }
    }
    return;  //不管下面的函数了
  }
  if (f[k] == 0)  //如果还没有被找过
  {
    for (int i = k + 1; i <= n; i++)  //往下搜索
    {
      if (f[i] == 0) {
        f[k] = i;
        f[i] = k;
        dfs(k + 1);
        f[k] = 0;
        f[i] = 0;  //回溯
      }
    }
  } else {
    dfs(k + 1);  //被找过就不管了
  }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);//输入坐标 
    qsort(a+1,n,sizeof(node),cmp);dfs(1);//排序，并dfs 
    printf("%d\n",ans);//最后输出就好了 
    return 0;
}