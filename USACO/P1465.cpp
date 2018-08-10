#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int ansI, ansV, ansX, ansL, ansC, ansD, ansM;
int i[20], v[20], x[20], l[20], c[20], d[20], m[20], a[20];
int n;
void mem() {
	a[1] = 1; i[1] = 1; // I
	a[2] = 4; i[2] = 1; v[2] = 1; // IV
	a[3] = 5; v[3] = 1; // V
	a[4] = 9; i[4] = 1; x[4] = 1; //IX
	a[5] = 10; x[5] = 1; //X
	a[6] = 40; x[6] = 1; l[6] = 1; //XL
	a[7] = 50; l[7] = 1; //L
	a[8] = 90; x[8] = 1; c[8] = 1; //XC
	a[9] = 100; c[9] = 1; //C
	a[10] = 400; c[10] = 1; d[10] = 1; //CD
	a[11] = 500; d[11] = 1; //D
	a[12] = 900; c[12] = 1; m[12] = 1; //CM
	a[13] = 1000; m[13] = 1; //M
}
void add(int b, int num) {
	ansI += i[b] * num;
	ansV += v[b] * num;
	ansX += x[b] * num;
	ansL += l[b] * num;
	ansC += c[b] * num;
	ansD += d[b] * num;
	ansM += m[b] * num;
}
int main() {
	cin >> n;
	memset(i, 0, 20);
	memset(v, 0, 20);
	memset(x, 0, 20);
	memset(l, 0, 20);
	memset(c, 0, 20);
	memset(d, 0, 20);
	memset(m, 0, 20);
	memset(a, 0, 20);
	mem();
	for (int i = 1; i <= n; i++) {
		int temp = i;
		for (int j = 13; j >= 1; j--) {
			if (temp == 0) {break;}
			while (temp < a[j]) {
				j--;
			}
			add(j, temp / a[j]);
			temp = temp % a[j];
		}
	}
	if (ansI != 0) printf("I %d\n", ansI);
	if (ansV != 0) printf("V %d\n", ansV);
	if (ansX != 0) printf("X %d\n", ansX);
	if (ansL != 0) printf("L %d\n", ansL);
	if (ansC != 0) printf("C %d\n", ansC);
	if (ansD != 0) printf("D %d\n", ansD);
	if (ansM != 0) printf("M %d\n", ansM);
	return 0;
}