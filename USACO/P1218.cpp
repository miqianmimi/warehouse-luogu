#include <cstdio>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int last[5]={0,1,3,7,9};
int a[5]={0,2,3,5,7};
int b[10]={0,23,29,31,37,53,59,71,73,79};
int c[9][1000];
void initialize(){
	for(int i=1;i<=4;i++){
		c[1][i]=a[i];
	}
	for(int i=1;i<=9;i++){
		c[2][i]=b[i];
	}
}
bool is_prime(int x){
	int i=3;
	if ((x%2)==0) return false;
	while(i*i<x){
		if (x%i==0){
			return false;
		}
		i=i+2;
	}
	return true;
}
int generate(int n){
	if(n==2){
		int num=9;
		return num;
	}
	int num ;
	num = generate(n-1);
	int cnt=0;
	for (int i =1;i<=num;i++){
		for (int j = 1; j<=4;j++){
			int temp = c[n-1][i]*10 + last[j];
			if (is_prime(temp)){
				c[n][cnt+1]=temp;
				cnt++;
			}
		}
	}
	return cnt; 
}
int main(){
	cin>>n;
	initialize();
	if (n==1){
		for(int i=1;i<=4;i++)
			cout<<a[i]<<endl;
		cout<<"\n"<<endl;
		return 0;
	}
	else{
		int num = generate(n);
		for(int i=1;i<=num;i++){
			cout<<c[n][i]<<endl;
		}
		cout<<"\n"<<endl;
		return 0;
	}
}