#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int timel[1001000][2];
int n;
int minimum=2e9;
int maximum=0;
int own=0;
int notown=0;
bool is_cover[1001000];
int main(){
	cin>>n;
	int i=1;
	while(i<=n) {scanf("%d %d",&timel[i][0],&timel[i][1]);i++;} 
	for (int i=1;i<=n;i++){
		if(timel[i][1]>maximum) maximum=timel[i][1];
		if(timel[i][0]<minimum) minimum=timel[i][0];
	}
	for (int i=minimum;i<=maximum;i++)
		is_cover[i]=0;
	for (int i=1;i<=n;i++){
		for(int j=timel[i][0];j<timel[i][1];j++){
			is_cover[j]=1;
		}
	}
	for(int i=minimum;i<maximum;i++){
		int c=0 ;
		while(is_cover[i]==1){
			i=i+1;
			c=c+1;
		}
		if(c!=0){if(own<c)own=c;}
	}
	for(int i=minimum;i<maximum;i++){
		int c=0 ;
		while(is_cover[i]==0){
			i=i+1;
			c=c+1;
		}
		if(c!=0){if(notown<c)notown=c;}
	}
	cout<<own<<" "<<notown<<"\n";
	return 0;
}