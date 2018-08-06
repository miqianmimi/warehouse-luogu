#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int a[3];
//其中a[1],a[2]分别表示总容量和现有牛奶
int b[3];
int c[3];
int ans[100];
int num=0;
//其中ans表示可能的c中容量
bool vis[22][22][22]= {false};
//表示谁已经给谁倒过牛奶了
#define COPY(dst, src) memcpy(dst, src, 3*4)

void add_milk(int m[],int n[]){ //a倒给b
 cout<<"当前状态："<<endl;
 cout<<"a: "<<"容量: "<<a[1]<<"目前: "<<a[2]<<endl;
 cout<<"b: "<<"容量: "<<b[1]<<"目前: "<<b[2]<<endl;
 cout<<"c: "<<"容量: "<<c[1]<<"目前: "<<c[2]<<endl;
 
 if (m[2]+n[2]>=n[1]){
  m[2] -= n[1]-n[2];
  n[2] = n[1];
 }
 else{
  n[2] += m[2];
  m[2] = 0;
 }
 cout<<"之后状态："<<endl;
 cout<<"a: "<<"容量: "<<a[1]<<"目前: "<<a[2]<<endl;
 cout<<"b: "<<"容量: "<<b[1]<<"目前: "<<b[2]<<endl;
 cout<<"c: "<<"容量: "<<c[1]<<"目前: "<<c[2]<<endl;
}
void dfss(int * a, int * b,int * c){
 if (vis[a[2]][b[2]][c[2]]) return; 
 else {
  vis[a[2]][b[2]][c[2]] = true;
 }
 int d[3],e[3],f[3];
 COPY(d,a);
 COPY(e,b);
 COPY(f,c);
 for (int i = 1;i<=3;i++){
  for(int j = 1;j<=3;j++){
   if(i!=j){
    if(i==1&&j==2){if(a[2]!=0 && b[2]!=b[1]) {cout<<i<<"->"<<j<<endl;add_milk (a,b);}}
    else if(i==1&&j==3){if(a[2]!=0 && c[2]!=c[1]) {cout<<i<<"->"<<j<<endl;add_milk (a,c);}}
    else if(i==2&&j==1){if(b[2]!=0 && a[2]!=a[1]) {cout<<i<<"->"<<j<<endl;add_milk (b,a);}}
    else if(i==2&&j==3){if(b[2]!=0 && c[2]!=c[1]) {cout<<i<<"->"<<j<<endl;add_milk (b,c);}}
    else if(i==3&&j==1){if(c[2]!=0 && a[2]!=a[1]) {cout<<i<<"->"<<j<<endl;add_milk (c,a);}}
    else if(i==3&&j==2){if(c[2]!=0 && b[2]!=b[1]) {cout<<i<<"->"<<j<<endl;add_milk (c,b);}}
    if(a[2]==0 && ans[c[2]]==0){
     ans[c[2]]=1;
     num++;
    }
    dfss(a,b,c);
    COPY(a,d);
    COPY(b,e);
    COPY(c,f);
   }
  }
 }
}
//状态，标记
int main(){
 while(cin>>a[1]>>b[1]>>c[1]){
  a[2]=0;
  b[2]=0;
  c[2]=c[1];
  memset(ans,0,sizeof(ans));
  ans[c[2]]=1;
  dfss(a, b, c);
  //print result
  for(int i=1;i<=c[1];i++){
   if(ans[i]==1){
    cout<<i<<" ";
   }
  }
  cout<<endl;
 }
 return 0;
}