#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef unsigned long long ULL;
int vis[20];
int main() {
	int n;
	cin >> n;
	for (int q = n + 1;; q++) {
		memset(vis, 0, sizeof(vis));
		char s[25];
		sprintf(s, "%d", q);
		int len = strlen(s);
		int ok = 1;
		for (int j = 0; j < len; j++) if (s[j] == '0') ok = 0;
		if (!ok) continue;
		for (int j = 0; j < len; j++)
		{
			int num = s[j] - '0';
			if (vis[num]) {ok = 0; break;}
			vis[num] = 1;
		}
		if (!ok) continue;
		int now = 0;
		memset(vis, 0, sizeof(vis));
		vis[0] = 1;
		for (int j = 0; j < len - 1; j++)
		{
			int nxt = (now + s[now] - '0') % len;
			if (vis[nxt]) {ok = 0; break;}
			vis[nxt] = 1;
			now = nxt;
		}
		int nxt = (now + s[now] - '0') % len;
		if (nxt != 0) ok = 0;
		if (ok) {cout << q << endl; return 0 ;}
	}
	return 0;
}
