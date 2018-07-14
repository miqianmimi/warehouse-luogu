#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int action[4]={0,1,2,3};
int a=1,b=1;
int n;
int main(){
	scanf("%d",&n);
	int c=0;
	for(int i=1;i<=n-1;i++){
		if (c==2) {a=a+1;b=b;}
		else if(c==3){a=a-1;b=b+1;}
		else if(c==0){a=a;b=b+1;}
		else if(c==1){a=a+1;b=b-1;}
		if(a==1 || b==1){
			c=(c+1)%4;
		}
	}
	cout<<a<<'/'<<b;
	cout<<'\n';
	return 0;
}
