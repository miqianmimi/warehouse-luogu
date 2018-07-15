#include<string.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	struct Statistic{
		int c[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	};
	char s[10000];
	char temp[1000];
	int size;
	struct Statistic my;
	for (int i = 0; i < 4 ;i++) {
		fgets(temp,1000,stdin);
		strcat(s,temp);
	}
	for(int i=0;;i++){
		if(s[i]=='\0'){
			size = i;
			break;
		}
	}
	for(int i = 0; i < size;i++){
		for (int j = 0; j < 26;j++){
			if(s[i] =='A'+j){
				my.c[j]+=1;
			}
		}
	}
	int max=0;
	for (int i=0;i<26;i++){
		if (max<my.c[i]) max=my.c[i];
	}
	for(int i=max;i>=1;i--){
		for (int j=0;j<26;j++){
			if (my.c[j] >= i){
				cout<<'*'<<' ';
				my.c[j]--;
			}
			else{
				cout<<' '<<' ';
			}
		}
		cout<<'\n';
	}
	for (int j=0;j<26;j++){
			char mm = 'A'+j;
			cout<<mm<<' ';
	}
	cout<<'\n';
	return 0;
}
