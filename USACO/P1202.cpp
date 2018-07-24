#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int year;
int a[8];
int what11;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month_run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool run;
bool isrun(int year){
	if (year%100 ==0){
		if(year%400==0){
			run=true;
		}
		else{
			run=false;
		}
	}
	else if(year%4==0){
		run=true;
	}
	else{
		run=false;
	}
	return run;
}
int computefirstday(int year){
	int sum = 0;
	for(int i=1900;i<=year-1;i++){
		if (isrun(i)){
			sum += 366;
		}
		else{
			sum += 365;
		}
	}
	int a = sum % 7 + 1;
	return a;
}

void computeyear(int year){
	what11 = computefirstday(year);	
	if (isrun(year)){
		int temp = 12 + what11;
		for(int i=0;i<=11;i++){
			temp = (temp + month_run[i])%7;
			a[temp] += 1;
		}	
	}
	else{
		int temp = 12 + what11;
		for(int i=0;i<=11;i++){
			temp = (temp + month[i])%7;
			a[temp] += 1;
		}
	}
	return;
}
int main(){
	memset(a,0,8);	
	int n;
	cin>>n;
	for(int i=1900;i<=n-1+1900;i++){
		computeyear(i);
	}
	for(int i=6;;i=(i+1)%7){
		cout<<a[i]<<' ';
		if(i==5){cout<<'\n';break;}
	}	
	return 0;
}
