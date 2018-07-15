#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
int main(){
	int K;
	scanf("%d",&K);
	double S = 0;
	for (int i=1; ;i++){
		S = S + 1.0/i;
		if (S > K){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
