#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
struct node
{
	int len;
	char ss[21];
} a[210];
int n, len;
char st[210000], s[110];
bool f[210000];
inline int cmp(const void *xx, const void *yy) { //快排算法
	node x = *(node*)xx;
	node y = *(node*)yy;
	if (x.len > y.len) return 1;
	if (x.len < y.len) return -1;
	return 0;
}
int main()
{
	int i, j, k, t;
	while (1) //输入单词
	{
		n++;
		cout << n << endl;
		scanf("%s", a[n].ss + 1);
		cout << a[1].ss + 1 << endl;
		cout << a[1].ss << endl;
		a[n].len = strlen(a[n].ss + 1);
		if (a[n].len == 1 && a[n].ss[1] == '.')
		{
			n--;
			break;
		}
	}

}