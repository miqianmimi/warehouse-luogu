#include<stdio.h>
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a * 10 + b;
	int num = int(sum/19);
	printf("%d\n",num);
	return (0);
}
