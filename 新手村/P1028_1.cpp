#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int f[1001];
int n;
int main(){
	f[1] = 1;
	f[2] = f[1] + 1;
	f[3] = f[1] + 1;
	f[4] = f[1] + f[2] + 1;
	f[5] = f[1] + f[2] + 1;
	cin>>n;
	for(int i = 6 ; i <= n ; i ++){
		for(int j = 1 ; j <= i/2 ; j ++){
			f[i] += f[j];
		}	
		f[i]++;
	}
	cout<<f[n];
	cout<<"\n";
	return 0;
}

