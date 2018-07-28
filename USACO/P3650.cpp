#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[10000],n,minn,s=1e9+1,sum;
int main()
{
	cin>>n;
	for(int i=1 ; i<=n ; i++)
		cin>>a[i];
	sort(a+1,a+n+1); //列举 //枚举法，如果
	for(int j=a[1] ; j<=a[n] ; j++)
	{
		sum = 0;
		for(int i=1 ; i<=n ; i++)
		{
			if( a[i] - j > 17 ) sum += (a[i]-j-17)*(a[i]-j-17); //比他大17。
			if( a[i] < j ) sum += (a[i]-j)*(a[i]-j); //比他小的，调整到他。
		}
		s = min(sum,s);
	}
	cout<<s<<endl;
	return 0;
}
