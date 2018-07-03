#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
int main(){
	int number;
	scanf("%d",&number);
	int count = 0;
	int lovely[number];
	for(int i = 0 ; i < number;i++){
		scanf("%d",&lovely[i]);
	}
	for(int i = 0 ; i < number ; i ++){
		count = 0 ;
		int a = lovely[i];
		for (int j = 0; j < i ;j++){
			if (lovely[j]<a){
				count += 1;
			}
		}
		if (i!=number-1){
			printf("%d ",count);
		}
		else{
			printf("%d\n",count);
		}
	} 
	return 0;
}


