#include <cstdio>
const int n = 10;
int a[n+1];
int c[n+1];
int choice = 3;
void dfs(int k,int count){
	if( count == choice){
		for(int i = 1; i <= choice;i++){
			printf("%d ",a[i]);	
		}
		printf("\n");
		return;
	}
	for(int i=a[k-1];i<=n;i++){	
		if (c[i]==0){
			c[i]=1;
			a[k]=i;
			dfs(k+1,count+1);
			c[i]=0;
		}

	}
} 
int main(){
	a[0]=1;
	for(int i = 1; i <= n ;i++){
		a[i]=i;
	}
	for(int i = 1; i <= n ; i++){
		c[i]=0;
	}
	dfs(1,0);
	return 0;
}
