#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int s,x,sum=0;
int main(){
	cin>>s>>x;
	double l = 7 ;
	int end = s + x ;
	while(true){
		if (sum >= s-x){
			if(sum + l > end){
				printf("n\n");
				return 0;
			}
			else{
				printf("y\n");
				return 0;
			}
		}
		sum += l;
		l = l*0.98;
	}
}
