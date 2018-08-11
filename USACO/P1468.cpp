#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
bool a[103]; //表示灯是否开着
int n, c;
bool kai[7];
bool guan[7];
int sign = 1;
int exist[9][7] =
{
	{0, 0, 0, 0, 0, 0}, // nonsense
	{1, 1, 1, 1, 1, 1}, // c = 0, 2                   1
	{0, 0, 0, 0, 0, 0}, //button1 c = 1, 2, 3         2
	{0, 1, 0, 1, 0, 1}, //button2 c = 1, 2, 3         3
	{1, 0, 1, 0, 1, 0}, //button3 c = 1, 2, 3         4
	{0, 1, 1, 0, 1, 1}, //button4 c = 1, 3            5
	{1, 0, 0, 1, 0, 0}, //button1+button4 c = 2, 3    6
	{1, 1, 0, 0, 0, 1}, //button2+button4 c = 2, 3    7
	{0, 0, 1, 1, 1, 0}  //button3+button4 c = 2, 3    8
};

void button1 () {
	for (int i = 1 ; i <= n; i++) {
		if (a[i] == 0) a[i] = 1;
		if (a[i] == 1) a[i] = 0;
	}
}
void button2 () {
	for ( int i = 1; i <= n ; i += 2) {
		if (a[i] == 0) a[i] = 1;
		if (a[i] == 1) a[i] = 0;
	}
}
void button3 () {
	for ( int i = 2; i <= n ; i += 2) {
		if (a[i] == 0) a[i] = 1;
		if (a[i] == 1) a[i] = 0;
	}
}
void button4 () {
	for ( int i = 1; i <= n ; i += 3) {
		if (a[i] == 0) a[i] = 1;
		if (a[i] == 1) a[i] = 0;
	}
}
void pd(int x) {
	for (int i = 1; i <= 6; i++) {
		if (kai[i] == 1 && exist[x][i - 1] != 1 || guan[i] == 0 && exist[x][i - 1] != 0)
			return;
	}
	sign = 0;
	for (int i = 1 ; i <= n ; i++) cout << exist[x][(i - 1) % 6];
	cout << endl;
}
int main () {
	cin >> n;
	memset(a, 1, sizeof(a));
	memset(kai, 0, 7);
	memset(guan, 1, 7);
	cin >> c;
	int temp;
	while (cin >> temp, temp != -1) kai[(temp - 1) % 6 + 1] = 1;
	while (cin >> temp, temp != -1) guan[(temp - 1) % 6 + 1] = 0;
	c = min(3, c);
	switch (c)
	{
	case 0:
	{
		pd(1);
		break;
	}
	case 1:
	{

		pd(2);
		pd(3);
		pd(5);
		pd(4);
		break;
	}
	case 2:
	{
		pd(1 + 1);
		pd(7 + 1);
		pd(2 + 1);
		pd(5 + 1);
		pd(3 + 1);
		pd(6 + 1);
		pd(0 + 1);
		break;
	}
	case 3:
	{
		pd(1 + 1);
		pd(7 + 1);
		pd(2 + 1);
		pd(4 + 1);
		pd(5 + 1);
		pd(3 + 1);
		pd(6 + 1);
		pd(0 + 1);
		break;
	}
	}
	if (sign == 1)
		cout << "IMPOSSIBLE" << endl;
	return 0;
}