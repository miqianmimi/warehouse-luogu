#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a,b,c;

int w(int a,int b,int c){
	if(a<=0 ||b<=0||c<=0){
		return 1;
	}
	else if(a>20 || b>20||c>20){
		return w(20,20,20);
	}
	else if(a<b && b<c){
		return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else{
		return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
}

int main(){
	while (true){	
		scanf("%d%d%d",&a,&b,&c);
		if(a==-1 &&b==-1&&c==-1){
			cout<<'\n';
			break;
		}
		int ans = w(a,b,c);
		cout<<'w'<<'('<<a<<','<<' '<<b<<','<<' '<<c<<')'<<' '<<'='<<' '<<ans<<"\n";
	}
	return 0;
}
