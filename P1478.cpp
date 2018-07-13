#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,s,a,b,cnt=0;
int apple[5010];
int li[5010];
void greedy(int s,int n,int high){
	int small = 1001;
	int small_i = 0;
	for(int i=1;i<=n;i++){
		if (apple[i]<=high){
			if(small>li[i]){small =li[i];small_i=i;}
		}
	}
	if(s>=small){
		cnt+=1;
		s=s-small;
		li[small_i]=1001;
		greedy(s,n,high);
	}
	else{
		return;
	}
	
}
int main(){
	cin>>n>>s;
	cin>>a>>b;
	int high=a+b;
	for(int i=1;i<=n;i++){cin>>apple[i]>>li[i];}
	greedy(s,n,high);
	//for(int i=1;i<=n;i++){cout<<apple[i]<<li[i]<<'\n';}
	cout<<cnt<<'\n';
	return 0;
}
