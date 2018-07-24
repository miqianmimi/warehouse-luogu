#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,i,ii,iii;
int temp;
char zhuzi[1000];
int collect[1000];
void duan(int site){
	if (site==1){
		char temp = zhuzi[1];
		int cnt=1; 
		int i = 2;
		if (temp =='w'){
			while (zhuzi[i]=='w'){
				i=i+1;
				if (i==n+1)i=1;
				cnt++;
			}
			temp = zhuzi[i];
		}
		while(zhuzi[i]==temp||zhuzi[i]=='w'){
			i++;
			cnt++;
		}
		temp = zhuzi[n];
		cnt++;
		i = n-1;
		if (temp =='w'){
			while (zhuzi[i]=='w'){
				i=i-1;
				if (i==0)i=n;
				cnt++;
			}
			temp = zhuzi[i];
		}
		while(zhuzi[i]==temp||zhuzi[i]=='w'){
			i--;
			cnt++;
		}
		collect[site]=cnt;
	}
	else{
		char temp = zhuzi[site];//b
		int cnt = 1;//1
		int ii = site+1;//n+1 site =29
		if (ii==n+1){ii=1;}//ii=1
		if (temp == 'w'){
			while(zhuzi[ii]=='w'){
				ii=ii+1;
				if (ii==n+1)ii=1;
				cnt++;
			}
			temp=zhuzi[ii];
		}
		while(zhuzi[ii]==temp||zhuzi[ii]=='w'){
			ii=ii+1; //ii=2
			if(ii==n+1)ii=1;
			cnt++; //cnt =2
		}
		if (site==1){
			temp=zhuzi[n];
		}
		else{
			temp=zhuzi[site-1];//r
		}
		cnt++;//3
		int iii=site-2;
		if(iii==0){iii=n;} //27
		if (iii==-1){iii=n-1;}	
		if (temp == 'w'){
			while(zhuzi[iii]=='w'){
				iii=iii-1;
				if(iii==0){iii=n;}
				cnt++;
			}		
			temp=zhuzi[iii];
		}
		while(zhuzi[iii]==temp||zhuzi[iii]=='w'){
			iii=iii-1; //26,25,24
			if(iii==0){iii=n;}
			cnt++; //4,5,6
		}
		collect[site]=cnt;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>zhuzi[i];
	}
	for(int i=1;i<=n;i++){
		duan(i);
	}
	//cout<<"最后一个"<<collect[29]<<'\n';
	int max=0;
	for(int i=1;i<=n;i++){
		//cout<<collect[i]<<'\n';
		if (max<collect[i]) max=collect[i];
	}
	cout<<max<<'\n';
	return 0;
}
