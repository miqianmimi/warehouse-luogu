#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
int n;
int m;
ll dp[1000000 + 10];
int main () {
	cin >> n;
	m = (n + 1) * n / 2;
	if (m % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	m = m / 2;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m ; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	cout << dp[m] / 2 << endl;
	return 0;
}