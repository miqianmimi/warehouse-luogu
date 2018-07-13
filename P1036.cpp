#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,k,cnt=0,s=0;
int num[21];
bool f[21];
int prime(int n){
	if (n == 2) {return 1;}
	for(int i = 2 ; i <= n/2 ; i++){
		if (n % i == 0){ return 0;}
	}
	return 1;
}
void xs(int x, int y){
	// x 为已经选了几个数，Y 为选第几个数
	for (int i = y; i <= n ;i ++){
		// y~n 循环是为了避免重复出现
		f[i] = false; //已选过
		s += num[i]; //值加入到s中
		if (x==k) //已经加到k个了，判断素数
		{
			if(prime(s)==1)cnt++; 
		}
		else {xs(x+1,i+1);}//继续搜寻下一个

		s -= num[i]; //累加器s减去a[i]的值
		f[i] = true; //f[i]变回true
	}
}
int main(){
	cin>>n>>k ;
	for (int i = 1 ; i <= n ; i ++){
		scanf("%d", &num[i]);
		f[i] = true;
	}
	xs(1,1);
	cout<<cnt;
	cout<<"\n";
	return 0;
}
