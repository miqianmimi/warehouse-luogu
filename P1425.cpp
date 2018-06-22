#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int hour,min;
	if( d > b )
	{
		hour = c - a ;
		min = d - b ;
	}
	else
	{
		hour = c - a - 1 ; 
		min = 60 - b + d ;
	}
	printf("%d %d\n",hour,min);
	return 0;
}

