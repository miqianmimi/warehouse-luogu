#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int ii;
	scanf("%d",&ii);
	string a;
	cin>>a;
	int i = 0;
	for(;i<a.size();i++){
		a[i]=(a[i]-'a'+ii)%26+'a';
	}
	cout<<a<<'\n';
	return 0;
}
