#include <stdio.h>
#include <iostream>
using namespace std;
char a[1000];
int N, S, cnt = 0;
bool judge(int x, int b) {
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
int main() {
  scanf("%d %d", &N, &S);
  int i = S+1;
  while (cnt < N) {
    int lst = 0;
    for (int m = 2; m <= 10; m++) {
      if (judge(i, m) == 1) {
        lst++;
      }
      if (lst == 2) {
        break;
      }
    }
    if (lst == 2) {
      printf("%d\n", i);
      cnt++;
    }
    i++;
  }
  printf("\n");
  return 0;
}
