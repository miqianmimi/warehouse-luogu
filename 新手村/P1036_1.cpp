#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,k,sum=0,cnt=0;
int ans=0;
int num[21];
bool prime(int n){
	if (n==2)return true;
	for(int i=2;i<=n/2;i++){
		if (n % i == 0) return false;
	}
	return true;
}
void dfs(int m,int all,int sum){
	if (m==n+1 || all == k){
		if(prime(sum) && all==k )ans++;
		return;
	}
	dfs(m+1,all+1,sum+num[m]);
	dfs(m+1,all,sum);
	return;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	dfs(1,0,0);
	cout<<ans;
	cout<<"\n";
	return 0;
}
