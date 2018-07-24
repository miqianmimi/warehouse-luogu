#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m;
int room_everyday[10086]={0};
int rent[10086][3];
int room_isrent[10086][10000];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&room_everyday[i]);}
	for(int i=1;i<=m;i++){scanf("%d %d %d",&rent[i][0],&rent[i][1],&rent[i][2]);}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=room_everyday[i];j++){
			room_isrent[i][j]=1;
		}
	}
	for(int d=1;d<=n;d++){
		for(int i=1;i<=m;i++){
			for(int j=rent[i][1];j<=rent[i][2];j++){
				room_everyday[j]-=1;
			}
			for(int t=1;t<=n;t++){
				if(room_everyday[t]<0){
					printf("-1\n");
					printf("%d\n",i);
					return 0;
				}
			}
		}
	}
	printf("0\n");
	return 0;
}
