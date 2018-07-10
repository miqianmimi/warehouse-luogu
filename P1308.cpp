#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
void convert(string &p){
	int i = 0;
	while (p[i]!='\0')
	{
		if (p[i]>='A' && p[i]<='Z'){
			p[i] = p[i] - 'A' +'a';
		}
		i++;
	}
}
//传一个指针，可以使得它改内部的值。
int main(){
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.length();i++){
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i< b.length();i++){
		b[i] = tolower(b[i]);
	}
	a=' '+a;
    b=' '+b+' ';
	if (b.find(a) == string::npos){
		cout<<-1<<endl;
	}
	else{
		int alpha = b.find(a);
		int beta = b.find(a), s=0;//计数器s
		while( beta!=string::npos){
			++s;
			beta = b.find(a,beta+1);
		}
		cout<<s<<" "<<alpha<<endl;
	}
	return 0;
}
