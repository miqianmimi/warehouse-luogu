#include <cstdio>
#include <iostream>
using namespace std;
int n, many, d;
int a[100];
int isdiff(int a, int b) {
	int tmp = a ^ b, anss = 0; //anss表示海明码
	//‘^’为按位异或符号，在二进制内，如果两个不一样则为1，一样则为0（例：1100101^1011001=0100100）
	while (tmp > 0)
	{
		anss += (tmp & 1); tmp >>= 1; //这一位为1（即这两位不一样）则anss++//向右移一位
	}
	return anss;
}
int main() {
	cin >> n >> many >> d;
	a[1] = 0;
	int cnt = 1;
	int i = 1;
	while (cnt <= n) {
		for (int j = 1; j <= cnt; j++) {
			if (__builtin_popcount(i ^ a[j]) < d) //isdiff(i, a[j]) < d
				goto c1;
		}
		cnt++;
		a[cnt] = i;
c1:
		i++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}