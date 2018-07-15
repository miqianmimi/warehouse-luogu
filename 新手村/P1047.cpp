#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
int main(){
	int length = 0 ;
	int line = 0 ;
	scanf("%d %d",&length,&line);
	int begin[line];
	int end[line];
	int vis[10000+10];
	int cnt = 0;
	memset(vis,0,sizeof(vis));
	for (int a = 0 ; a < line; a++){
		scanf("%d %d",&begin[a],&end[a]);
	}
	for (int i = 0 ; i < line ; i++){
		for (int j = begin[i]; j <= end[i] ; j++){
			if (vis[j]==0){
				vis[j] = 1;
			}
		}
	}
	for (int i = 0 ; i <= length;i++){
		if ( vis[i] == 0 ){
			cnt += 1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
