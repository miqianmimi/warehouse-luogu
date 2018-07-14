#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int a[5000];
bool prime(int n){
	if (n==2){return true;}
	for(int i = 2; i*i <= n ;i++){
		if(n%i==0){return false;}	
	}
	return true;
}
int main(){
	scanf("%d",&n);
	int count = 0;
	for(int i=2;i<=n;i++){
		if(prime(i)){count++; a[count] = i;}
	}
	for(int i=1 ;i <= count ; i++){
		for (int j=i; j<=count;j++){
			for(int m=j; m<=count;m++){
				if (a[i]+a[j]+a[m]==n){
					cout<<a[i]<<' '<<a[j]<<' '<<a[m]<<'\n';
					return 0;
				}
			}
		}		
	}
}
