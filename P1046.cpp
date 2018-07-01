#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
int main(){
	int high ;
	int apple[10] ;
	for (int m = 0 ; m < 10 ; m ++ ){
		scanf( "%d",&apple[m]) ; 		
	}
	scanf("%d",&high);
	int count = 0 ;
	for (int m = 0 ; m < 10 ; m ++ ){
		if (high + 30 >= apple[m]) {
			count += 1 ;
		}
	}
	printf("%d\n",count);
	return 0 ;
}
