#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i = 0;
	char p;
	while(s[i] <= '9' && s[i] >= '0'){
		i = i + 1;
	}
	//记录第一个数组长度
	p = s[i];
	enum status {integer,decimal,fraction, percentage};
	enum status sta;
	if (s[i] == '.') sta=decimal;
	else if (s[i] == '/') sta= fraction;
	else if (s[i] == '%') sta= percentage;
	else sta = integer;
	int x = i;
	i--;
	while(s[i]=='0'&& i>0) i --;
	for (int j = i; j >= 0 ; j--){
		cout<<s[j];
	}
	if  (sta == 0) {
		cout<<"\n";
		return 0;
	}
	else if (sta == 3){
	   cout<<"%\n";	
	   return 0;
	}
	else{
		cout<<p;
		int m = s.size() - 1;
		while(s[x+1]=='0'&& x<m-1)x++;
		while(s[m]=='0' && m>x+1) m--;
		for (int j = m;j>x;j--)
			cout<<s[j];
		cout<<"\n";
	}
	return 0;
}
