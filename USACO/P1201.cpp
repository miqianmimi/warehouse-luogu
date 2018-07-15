#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int NP;
string name[11];
double money[11];
string temp;
string temp2;
int temp_num;
int temp_money;
int i,j,m,t;
int main(){
	memset(money,0,11);
	cin>>NP;
	//cout<<"NP:"<<NP<<'\n';
	for(i=1;i<=NP;i++){
		cin>>name[i];
	}
	for(i=1;i<=NP;i++){
		//cout<<"name:"<<name[i]<<'\n';
		cin>>temp;
		for(j=1;j<=NP;j++){
		//	cout<<"temp:"<<temp<<'\n';
			if (temp==name[j]){
				scanf("%d %d",&temp_money,&temp_num);
				if (temp_money==0&&temp_num==0){
					break;
				}
				temp_money = temp_money/temp_num;
				money[j] = money[j]-temp_money*temp_num;
				for(m=1;m<=temp_num;m++){
					//cout<<3<<'\n';
					cin>>temp2;
					for(t=1;t<=NP;t++){
					//	cout<<4<<'\n';
						if(temp2==name[t]){
							money[t]=money[t]+temp_money;
							break;
						}
					}
				}
				break;
			}
		}
	}
	//cout<<"answer\n";
	for(i=1;i<=NP;i++){
		cout<<name[i]<<' '<<money[i]<<'\n';
	}
	return 0;
}
