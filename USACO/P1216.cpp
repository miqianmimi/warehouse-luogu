#include <bits/stdc++.h>
#define fp(i,l,r) for(register int i=(l);i<=(r);i++)
#define fd(i,r,l) for(register int i=(r);i>=(l);i--)

using namespace std;
int _ans = 0;
int n;
int a[1003][1003];
int f[1003][1003];
inline int _max(int a,int b){
	if (a>b){
		return a;
	}
	return b;
}
inline int search(int x,int y){
	int _ans = 0;
	if(x==n){
		return a[x][y];
	}
	if(f[x+1][y]==-1){
		f[x+1][y]=search(x+1,y);
	}
	if(f[x+1][y+1]==-1){
		f[x+1][y+1]=search(x+1,y+1);
	}
	_ans = _max(f[x+1][y],f[x+1][y+1])+a[x][y];
	return _ans;
}
int main(){
	freopen("P1216.in", "r", stdin);
	//freopen("P1216.out", "w", stdout);
	scanf("%d",&n);
	fp(i,1,n){
		fp(j,1,i){
			scanf("%d",&a[i][j]);
			f[i][j]=-1;
		}
	}
	printf("%d",search(1,1));
	cout<<'\n'<<endl;
	return 0;
}
