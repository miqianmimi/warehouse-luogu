#include <bits/stdc++.h>
#define fp(i,l,r) for(register int i=(l);i<=(r);i++)
#define fd(i,r,l) for(register int i=(r);i>=(l);i--)
using namespace std;
inline int _max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int a[1003][1003],f[1003][1003];
int main(){
    int n;
    scanf("%d",&n);
    fp(i,1,n){
        fp(j,1,i){
            scanf("%d",&a[i][j]);
            f[i][j]=a[i][j];
        }
    }
    fd(i,n-1,1){
        fp(j,1,i){
            f[i][j]=_max(f[i+1][j],f[i+1][j+1])+a[i][j];
        }
    }
    printf("%d\n",f[1][1]);
    return 0;
}
