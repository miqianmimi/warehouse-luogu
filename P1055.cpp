#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	char a[14] ;
	int b = 0 ;
	int sum = 0 ;
	scanf("%c-%c%c%c-%c%c%c%c%c-%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&b);
	for( int i = 1 ; i <= 9 ; i ++ ){
		sum += (a[i - 1] - '0') * i;
	}
	if ( sum % 11 == b ){
		printf("Right\n");
	} 
	else {
		int right = sum % 11;
		printf("%c-%c%c%c-%c%c%c%c%c-%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],right);
	}
	return 0 ;
}
