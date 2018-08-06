#include <cstdio>
#include <iostream>
using namespace std;
int ans[1000]; //存储解
int a[1000]; //牛所需要最小维他命
int b[1000][1000]; //每种饲料所含维他命最少
int c[1000];//每次搜索选的饲料号
int n, m, minn = 1000000000;
bool pd(int x) // 判断是否已经达成终止条件
{
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= x; j++)
			sum += b[c[j]][i];
		if (sum < a[i]) return false;
	}
	return true;
}

void dfs(int t, int s) //t是往后搜索的量
{
	if (t > m) //边界
	{
		if (pd(s)) //s是当前选出的个数
		{
			if (s < minn) //判断是否是更小的个数
			{
				minn = s;
				for (int i = 1; i <= minn; i++)
				{
					ans[i] = c[i];
				}
			}
		}
		return;
	}
	c[s + 1] = t;
	dfs(t + 1, s + 1);
	c[s + 1] = 0;
	dfs(t + 1, s); //回溯一步
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n ; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= m ; i++) {
		c[i] = 0;
	}
	dfs(1, 0);
	cout << minn << ' ';
	for (int i = 1; i <= minn; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}