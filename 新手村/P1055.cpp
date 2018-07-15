#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	char a[14] ;
	char b ;
	char t ;
	int sum = 0 ;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&b);
	for( int i = 1 ; i <= 9 ; i ++ ){
		sum += (a[i - 1] - '0') * i;
	}
	t = sum%11 + '0';
	if (t =='0'+10) t = 'X';
	if ( t == b ){
		printf("Right\n");
	} 
	else {
		printf("%c-%c%c%c-%c%c%c%c%c-%c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],t);
	}
	return 0 ;
}
