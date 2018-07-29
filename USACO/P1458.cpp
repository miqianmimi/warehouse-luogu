#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int cnt=1;
const int maxn=160;
struct node{
	int a;
	int b;
	double a_b;
} f[maxn*maxn];
inline bool cmp(node a, node b){
	return a.a_b<b.a_b;
}

bool is_easy(int a,int b){
	if(a>b) 
	{	
		for(int i=2;i<=b;i++){
			if (a%i==0 && b%i==0){
				return false;
			}
		}
		return true;
	}
	else if(a==b) return false;
	else if(a<b){	
		for(int i=2;i<=a;i++){
			if (a%i==0 && b%i==0){
				return false;
			}
		}
		return true;
	}
}
int main(){
	cin>>n;
	//cout<<0<<'/'<<1<<endl;
	f[1].a = 0;
	f[1].b = 1;
	f[1].a_b = 0;
	//cout<<cnt<<endl;

	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--)
		{
			if (is_easy(i,j))
			{
				cnt++;
				f[cnt].a = i;
				f[cnt].b = j;
				f[cnt].a_b = i*1.0/j;
			  //cout<<i<<'/'<<j<<endl;
			}
		}
	}
	//cout<<1<<'/'<<1<<endl;
	cnt++;
	f[cnt].a=1;
	f[cnt].b=1;
	f[cnt].a_b=1;
	//cout<<cnt<<endl;
	sort(f+1,f+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<f[i].a<<'/'<<f[i].b<<endl;
	}
	cout<<'\n'<<endl;
	return 0;
}