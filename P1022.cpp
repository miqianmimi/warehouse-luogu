#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
double num = 0 , x = 0;//num是数字之和，x是系数之和
char c,p; //p是未知数，c是读入的每一个字符
int a[100],l=1,mid,pd;
//a[]储存每一个出现的数，l记录数组长度，mid分开等号，pd判断正负
int main(){
	memset(a,0,sizeof(a));//数组清0
	pd = 1;
	while(c!='='){
		c=getchar();
		if(c=='-')
			++l,pd=-1;
		if(c=='+')
			++l,pd=1;
		if(c>='0'&&c<='9'){
			if(!a[l])
				a[l]=(c-'0')*pd;
			else
				a[l]=a[l]*10+(c-'0')*pd;
		}
		if(c>='a'&&c<='z'){
			p=c;
			if(a[l]!=0)
				x+=a[l],a[l]=0;
			else
				x+=pd;
			--l;
		}
	}
	mid=l,++l,pd=1;
	while(c!='\n'){
		c=getchar();
		if(c=='-')
			++l,pd=-1;
		if(c=='+')
			++l,pd=1;
		if(c>='0'&&c<='9'){
			if(!a[l])
				a[l]=(c-'0')*pd;
			else
				a[l]=a[l]*10+(c-'0')*pd;
		}
		if(c>='a'&&c<='z')
		{
			p=c;
			if(a[l]!=0)
				x-=a[l],a[l]=0;
			else
				x-=pd;
			--l;
		}
	}
	for(int i=1;i<=l;++i){
		if(i<=mid)
			num-=a[i];
		else
			num+=a[i];
	}
	if(!(num/x))
		printf("%c=0.000\n",p);
	else
		printf("%c=%.3lf\n",p,num/x);
	return 0;
}
