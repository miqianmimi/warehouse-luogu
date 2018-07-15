#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
int a[10];
int f(int *arr) {
	return arr[0] * 100 + arr[1] * 10 + arr[2];
}
int main(){
	for (int i = 1; i <= 9; i++)
		a[i] = i;
	do {
		int x1 = f(a + 1);
		int x2 = f(a + 4);
		int x3 = f(a + 7);
		if (x1 * 2 == x2 && x1 * 3 == x3)
			printf("%d %d %d\n", x1, x2, x3);
		} while (std::next_permutation(a + 1, a + 9 + 1));
	return 0;
}
