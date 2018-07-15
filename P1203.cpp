#include<iostream>
#include<algorithm>
using namespace std;
string a;
int f(int x){
	int sum=0;
	char a1=a[x];
	char b2=a[x+1];
	for(int i=x;;i--)
	{
		if(a[i]==a1)sum++;
		else if(a[i]=='w')
			sum++;
		else
			break;
	}
	for(int i=x+1;;i++)
	{
		if(a[i]==b2)sum++;
		else if(a[i]=='w')sum++;
		else
			break;
	}
	return sum;
}
int main(){
	int ans,n;
	ans = -1;
	cin>>n;cin>>a;
	a = a+a+a;
	//从中间开始处理，两边都不会溢出
	for(int i=n;i<2*n;i++)
	{
	//	if(a[i]==a[i+1])
	//		continue;
		if(a[i]=='w')
		{
			a[i]='r';
			ans=max(ans,f(i));
			a[i]='b';
			ans=max(ans,f(i));
			a[i]='w';//还原
		}
		ans =max(ans,f(i));
	}
	ans=min(ans,n);
	//if(ans==-1)ans=n;
	cout<<ans<<endl;
	return 0;
}
