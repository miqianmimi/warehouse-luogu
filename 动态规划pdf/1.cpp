#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
int f[2000];
int n;
int num;
int a[20];
using namespace std;
void howmuch(int i,int n){
	int cnt = 0;
	while(true){
		if(((i>>cnt)& 1) ==1){
			a[cnt+1]=1;
		}
		else{
			a[cnt+1]=0;
		}
		cnt++;	
		if(cnt==n){break;}
	}          
}
int main(){
	cin>>n;
	num = (1<<n) -1;
	//cout<<num<<endl;
	f[0] = 1;
	for(int i=1;i<=num;i++){
		howmuch(i,n);
		for(int j=1;j<=n;j++){
			if(a[j]==1){
				f[i]+=f[i-(1<<(j-1))];
			}
		}
		//if (i>>j&1) f[i]+=f[i^(1<<j)];
		//if (i>>j&1) f[i]+=f[i^(1<<j)];
		//if (i>>j&1) f[i]+=f[i^(1<<j)];
		//if (i>>j&1) f[i]+=f[i^(1<<j)];
	//	cout<<" "<<f[i]<<" i: "<<i<<endl;
//		memset(a,0,sizeof(a));
	}


	cout<<f[num]<<endl;
	return 0;
}
