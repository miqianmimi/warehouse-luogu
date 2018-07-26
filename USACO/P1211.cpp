#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool hh[10];
bool p(long n){
	while (n){
		if(!hh[n%10]) return false;
		n /= 10;
	}
	return true;
}
int main(){
	long n, count = 0, a,b,c;
	memset(hh,false,sizeof(hh));
	cin>>n;
	for(int i = 1;i <= n;i++){	
		cin>>a;
			hh[a]=true;
	}
	for(int i = 100;i<=999;i++){
		if(!p(i)) continue;
			for(int j = 10;j<=99;j++){
				if(!p(j)) continue;
				a = i*(j%10);
				if(a>999) continue;
				if(!p(a)) continue;
				b = i * (j/10);
				if (b>999) continue;
				if(!p(b)) continue;
				c= i*j;
				if (c>9999) continue;
				if (!p(c)) continue;
				count++;
			}
	}
	cout<<count<<endl;
	return 0;
}