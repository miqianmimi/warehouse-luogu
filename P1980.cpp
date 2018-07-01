#include<cstdio>
int main(){
	int x;
	int n;
	scanf("%d %d",&n,&x);
	int count = 0 ;
	for (int i = 1; i <= n ; i ++ ){
		for (int a = i ; a > 0 ; a = (a - a % 10) / 10){
			int m = a % 10 ;
            if (m == x){
				count += 1;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
