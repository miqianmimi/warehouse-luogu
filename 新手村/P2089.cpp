#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[11];
int sum;
int cnt=0;
int choice[3]={1,2,3};
int b[11]= {0,0,0,0,0,0,0,0,0,0,0};
int c[20000][11];
void dfs(int now, int he){
	if (now == 11||he >= sum){
		if (he == sum && now == 11){
			for(int i = 1 ; i <= 10 ; i++){
				c[cnt][i]=b[i];
			}	
			cnt++;
		}
		return;
	}
	b[now]=1;
	dfs(now+1, he+1);
	b[now]=2;
	dfs(now+1, he+2);
	b[now]=3;
	dfs(now+1, he+3);
}
int main(){
	cin>>sum;
	dfs(1,0);
	cout<<cnt;
	cout<<'\n';
	for(int i=0;i<cnt;i++){
		for(int j=1;j<=10;j++){
			cout<<c[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
	//cout<<b[1]<<' '<<b[2]<<' '<<b[3]<<' '<<b[4]<<' '<<b[5]<<' '<<b[6]<<' '<<b[7]<<' '<<b[8]<<' '<<b[9]<<' '<<b[10]<<'\n';
}
