#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a,b,c;
bool num[10];
void change(int a){
	while(a>0){
		int m = a%10;
		num[m] -= 1;
		a = a/10;
	}
}
int main(){
	cin>>a>>b>>c;
	bool mmm = false;
	for(int i=123;i<=987/c*a;i++){
		int m = b*i/a;
		int j = c*i/a;
		for(int i=1;i<=9;i++) num[i]=1;	
		change(i);
		change(j);
		change(m);
		int cnt =0;
		for(int t = 1;t<=9;t++){
			if(num[t]==0){cnt++;}
		}
		if (cnt ==9){mmm=true;cout<<i<<' '<<m<<' '<<j<<'\n';}
	}
	if (!mmm){cout<<"No!!!\n";}

	return 0;
}
