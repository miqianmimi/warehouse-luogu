#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans = 0;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int a[4001];
int main(){
	cin>>n;
	n=n-4;
	for(int i=0;i <= 4000;i++){
		int m = i;
		a[i]=0;
		while(true){
			a[i]=num[m%10]+a[i];
			m = m /10;
			if (m==0){break;}
		}
	}
	for(int i=0;i<=2000;i++){
		for(int j=0;j<=2000;j++){
			if (a[i]+a[j]+a[i+j]==n){
				//cout<<i<<'+'<<j<<'='<<i+j<<'\n';
				ans++;}
		} 
	}
	cout<<ans;
	cout<<'\n';
	return 0;
}

