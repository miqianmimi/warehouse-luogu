#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
int N;
int main(){
	scanf("%d",&N);
	int weather[N];
	for (int i=0;i<N;i++){
		scanf("%d",&weather[i]);
	}
	int max = 1;
	for (int i=0;i<N;i++){
		int count = 1;
		for (int j=i+1;j<N;j++){
			if (weather[j]>weather[j-1])
				count ++;
			else{
				i = j - 1;
				break;
			}
		}
		if (count>max)
			max =count;
	}
	printf("%d\n",max);
	return 0;
}
