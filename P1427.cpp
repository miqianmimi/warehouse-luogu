#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
int main(){
	int numberlist[10000];
	memset(numberlist,0,sizeof(numberlist));
	int notend = true;
	int i = 0;
	while ( notend ){
		scanf("%d",&numberlist[i]);
		if (numberlist[i] != 0)
			i = i + 1 ;
		else {
			notend = false;
		}
	}
	for (int a = i ; a >= 0 ; a -- ){
		if (a == 0){
			printf("%d\n",numberlist[a]);
		}
		else if (a == i){
			continue;
		}
		else{
			printf("%d ",numberlist[a]);
		}
	}
	return 0;
}
