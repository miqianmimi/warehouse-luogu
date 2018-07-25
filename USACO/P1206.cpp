#include <stdio.h>
using namespace std;
int b;
char a[1000];
int g[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
bool judge(int x) {
  int m = 1;
  while (x != 0) {
    a[m] = x % b;
    x = x / b;
    m = m + 1;
  }
  m--;
  for (int i = 1; i <= (m + 1) / 2; i++) {
    if (a[i] != a[m + 1 - i]) {
      return false;
    }
  }
  return true;
}
void print(int x) {
  int m = 1;
  while (x != 0) {
    a[m] = x % b;
    x = x / b;
    m++;
  }
  m--;
  for (int i = m; i >= 1; i--)  //倒序输出
  {
    if (a[i] <= 9)
      printf("%d", a[i]);
    else
      printf("%c", g[a[i] - 10]);
  }
}
int main() {
  scanf("%d", &b);
  for (int i = 1; i <= 300; i++) {
    if (judge(i * i) == 1) {
      print(i);
      printf(" ");
      print(i * i);
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}
