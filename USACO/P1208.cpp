#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
//用结构体输入数据
//用函数排序
struct milk{
	int price;
	int amount;
}arr[5010];
bool cmp(milk a,milk b){
	return a.price<b.price;
}
int main(){
	int i,k,n,m,ans=0,qian=0;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>arr[i].price>>arr[i].amount;
	}
	sort(arr+1,arr+m+1,cmp);
	for(i=1;i<=m;i++){
		ans+=arr[i].amount;
		qian+=arr[i].price*arr[i].amount;
		if(n<=ans+arr[i+1].amount)break;
	}
	k = n - ans ;
	qian+= k*arr[i+1].price;
	cout<<qian<<endl;
	return 0;
}	
