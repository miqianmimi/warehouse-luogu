#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int b[200010],a[200010]; //a双平方数数组 b表示这个数已经在里面了。
bool cmp(int x, int y){
	return x>y;
}
struct node{
	int u, v;
}w[200010];
bool tmp(node x,node y){
	if(x.u!=y.u) return x.u<y.u;
	return x.v<y.v;
}
int main(){
	int i,j,k,n,m, sum=0,num=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<=m;i++)
		for(j=0;j<=m;j++){
			if(b[i*i+j*j]==0)a[++sum]=i*i+j*j;
			b[i*i+j*j]=1;
		}
	sort(a+1,a+sum+1,cmp); //a从大到小排。
	for(i=1;i<=sum-n+1;i++)
		for(j=i+1;j<=sum-n+2;j++){
			int p = a[i] - a[j], q = n - 2, t = a[j], flag = 1;
			//p是公差，flag标记是否可成等差数列，q控制数列长度,t是当前首位
			if(t-(n-2)*p<0)break;//直接下一个。
			while(q){
				q --;
				t -= p;
				if(t < 0){
					flag = 0;
					break;
				}
				if (b[t]==0){
					flag = 0;
					break;
				}
			}
			if(flag==1){
				w[++num].u=p;
				w[num].v=t;
			}
		}
	if(num==0){
		printf("NONE\n");
		return 0;
	}
	sort(w+1,w+num+1,tmp);
	for(i=1;i<=num;i++)
		printf("%d %d\n",w[i].v,w[i].u);
	return 0;
}