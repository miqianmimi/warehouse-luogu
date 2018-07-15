#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int cnt=1;
int b;
int a[100];
int main(){
	cin>>b;
	if (b<0){
		cout<<'-';
		b=0-b;
	}
	while(true){
		a[cnt]=b%10;
		b=b/10;
		if(b==0){break;}
		cnt++;
	}
	for(int m = 1; m <= cnt;m++){
		if (m == 1){
			while(a[m]==0){
				m++;
			}
		}
		cout<<a[m];
	}
	cout<<'\n';
	return 0;
}
