#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long a,b,c;
long long d[21][21][21];
int w(long long a, long long b,long long c){
	if(a<=0 ||b<=0||c<=0){
		return 1;
	}
	if(d[a][b][c]){
		return d[a][b][c];
	}
	else if(a>20 || b>20||c>20){
		return d[20][20][20];
	}
	else if(a<b && b<c){
		d[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else{
		d[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
	return d[a][b][c];
}

int main(){
	while (true){	
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==-1 &&b==-1&&c==-1){
			break;
		}
		long long ans;
        if(a <= 0 || b <= 0 || c <= 0){
            ans = 1;
        }
        else if(a > 20 || b > 20 || c > 20){
            ans = w(20, 20, 20);
        }
        else{
            ans = w(a, b, c);
        }
		cout<<'w'<<'('<<a<<','<<' '<<b<<','<<' '<<c<<')'<<' '<<'='<<' '<<ans<<"\n";
	}
	return 0;
}
