#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ff[26];//定义计数数组
int main()
{
    int i,j,n,maxn=0;char a[81];
    for(i=0;i<4;i++)
    {
        gets(a);//gets读入
        n=strlen(a);
        for(j=0;j<n;j++)if(a[j]>='A'&&a[j]<='Z')ff[a[j]-'A']++;//统计字符出现次数
    }
    for(i=0;i<26;i++)maxn=max(maxn,ff[i]);//最多次数（最高柱状图）
    for(i=maxn;i>0;i--){
    for(j=0;j<26;j++)
    if(ff[j]>=i)printf("* ");else printf("  ");//模拟，是可以输出的就输出*，否则跳过
    printf("\n");}//换行
    for(i=0;i<26;i++)printf("%c ",i+'A');//输出a~z
}
