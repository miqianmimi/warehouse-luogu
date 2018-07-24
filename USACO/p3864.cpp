#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
string name[5000];
char ft[10][4]={{},{},"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int main(){
	int n=0;
	while (cin>>name[n]) n++;
	string x=name [0];
	n-- ;
	sort(name+1,name+n+1);// 排序，方便按字典顺序输出
	bool none = 1 ;//是否无答案
	for(int i=1;i<=n;i++)
	{
		bool can=(name[i].size()==x.size());
		//can 表示是否能对应，如果name[i]与x长度不等就直接判为补鞥呢
		for(int j=0;j<name[i].size();j++)
		{
			char c=name[i][j];
			can=can & (c==ft[x[j]-'0'][0] || c==ft[x[j]-'0'][1] || c==ft[x[j]-'0'][2]);
		}
		if (can) printf("%s\n",name[i].c_str()),none=0;//c_str()把string转化成char*
		//只要输出，none就可以赋值0.
	}
	if(none) cout<<"NONE\n";
	return 0;
}
