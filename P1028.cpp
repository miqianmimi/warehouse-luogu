#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
int n;
int cnt = 1;
void func(int x){
	for(int i=1;i<=x/2;i++){
		cnt ++;
		func(i);
	}
}
int main(){
	scanf("%d",&n);
	func(n);
	printf("%d\n",cnt);
	return 0;
}
