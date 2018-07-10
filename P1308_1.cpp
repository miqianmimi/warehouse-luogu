#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
void convert(string &p){
	int i = 0 ;
	while (p[i] != '\0'){
		if (p[i] >= 'A' && p[i]<='Z')
		{
			p[i] = p[i] + 32;
		}
		i++;
	}
}
int main(void){
	string key;
	string data;
	getline(cin,key);
	getline(cin,data);
	convert(data);
	convert(key);
	int flag = 0;
	int demo = -1;
	int i = 0 ; int j = 0;
	data = ' '+ data+' ';
	int l = key.length()-1;
	if (key[l]==' '){
		key = ' ' + key ;
	}
	else{
		key = ' '+ key + ' ';
	}
	while(data[i] != '\0')
	{
		if(flag == 0){
			demo = i;
		}
		while(data[i] == key[j]){
			if(j == key.length()-1 ){
				flag++;
				break;
			}
			i++;
			j++;
		}
		if (data[i] == ' '){
		}
		else{
			i ++ ;
		}
		j = 0;
	}
	if (flag != 0){
		cout<<flag<<" "<<demo<<"\n";
	}		
	else{
		cout<<-1<<"\n";
	}
	return 0;
}
