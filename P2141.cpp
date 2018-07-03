#include<cstring>
#include<iostream>
int n ;
int num[101];
int ans ;
int flag[100000];
int main(){
	scanf("%d",&n);
	memset(flag,0,sizeof(flag));	
	for (int i=0;i<n;i++){
		scanf("%d",&num[i]);
		flag[i] = 1;
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (flag[num[i]+num[j]]){
				flag[num[i]+num[j]]=0;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
