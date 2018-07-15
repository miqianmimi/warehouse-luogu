#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
int main(){
	char a[7];
	char b[7];
	scanf("%s",a);
	scanf("%s",b);
	int l = strlen(a);
	int j = strlen(b);
	int number1 = 1;
	int number2 = 1;
	for (int i = 0 ; i < l ; i ++ ){
		number1 = number1 * ((int)a[i] - 64);  
	}
	number1 = number1 % 47;
	for (int m = 0 ; m < j ; m ++ ){
		number2 = number2 * ((int)b[m] - 64);
	}
	number2 = number2 % 47;
	if (number1 == number2){
		printf("GO\n");
	}
	else{
		printf("STAY\n");
	}
	return 0;
}
