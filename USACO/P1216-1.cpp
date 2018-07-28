#include <bits/stdc++.h>
#define fp(i,l,r) for(register int i = (l); i<=(r);i++)
#define fl(i,r,l) for(register int i = (r); i>=(l);i--)

using namespace std;
int _ans = 0;
int n;
int a[1002][1002];
int f[1002][1002];
int _count = 0;
inline int _max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
inline int search(int x, int y){
	int _ans = 0;
	if(x==n){
		return a[x][y];
	}
	if (f[x+1][y]==-1){
		f[x+1][y]=search(x+1,y);
	}
	if (f[x+1][y+1]==-1){
		f[x+1][y+1]=search(x+1,y+1);
	}
	_ans = _max(f[x+1][y],f[x+1][y+1])+a[x][y];
	return _ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
			f[i][j]=-1;
		}
	}
	printf("%d\n",search(1,1));
	return 0;
}