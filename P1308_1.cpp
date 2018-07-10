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
	key = ' ' + key;
	while(data[i] != '\0')
	{
		if(flag == 0){
			demo = i;
		}
		while(data[i] == key[j]){
			i++;
			j++;
			if(key[j+1] == ' ' && (data[i+1] == ' ' || data[i+1] == '\0')){
				flag++;
				break;
			}
		}
		j = 0;
		i ++ ;
	}
	if (flag != 0){
		cout<<flag<<" "<<demo<<"\n";
	}		
	else{
		cout<<-1<<"\n";
	}
	return 0;
}
