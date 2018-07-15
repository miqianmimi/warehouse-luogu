#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
bool prime(int n){
	if (n==2) return true;
	for(int i=3;i*i<=n;i+=2){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}
int a[10];
bool palindromes(int n){
	int m = n;
	int cnt = 0;
	while(m!=0){
		a[cnt] = m % 10;
		cnt += 1;
		m = m/10;
	}
	if (cnt%2 == 0){
		for (int i = 0; i<=cnt/2-1;i++){
			if (a[i]!=a[cnt-i-1]) return false;
		}
	return true	;
	}
	else if (cnt%2 == 1){
		for (int i = 0; i<=(cnt-1)/2-1;i++){
			if (a[i]!=a[cnt-i-1]) return false;
		}
	return true;
	}
	return true;
}
bool ws(int k){
	if(k>=10 && k<100 && k!=11) return false;
	if(k>=1000 && k<10000)return false;
	if(k>=100000 && k<1000000)return false;
	if(k>=10000000 && k<100000000)return false;
	return true;
}
int main(){
	scanf("%d %d",&m,&n);
	if (m<=2) {cout<<2<<"\n"; m=5;}
	if (m%2==0) {m++;}
	for(int i=m;i<=n;i=i+2){
		if (ws(i)){
			if(palindromes(i)){
				if(prime(i)){
					cout<<i<<'\n';
				}
			}
		}
	}
	return 0;
}
