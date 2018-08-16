#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mod = 9901;
int dp[210][110], n, k; //树的节点 //树的高度
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) dp[1][i] = 1;
	for (int tk = 1; tk <= k; tk++)
		for (int i = 3; i <= n; i += 2)
			for (int j = 1; j < i; j += 2)
				(dp[i][tk] += dp[j][tk - 1] * dp[i - j - 1][tk - 1]) %= Mod;
	printf("%d", (dp[n][k] - dp[n][k - 1] + Mod) % Mod);
	return 0;
}

//即：dp[i][j]=sigma(dp[t][j-1]*dp[i-t-1][j-1]),是不是很简单？
//考虑一下初始化：把dp[1][]都设成1就好了，然后枚举点的个数时只需要枚举奇数（这个很容易想到）。

