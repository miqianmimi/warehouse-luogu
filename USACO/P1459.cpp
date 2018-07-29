#include <algorithm>
#include <iostream>//头文件
#include <cstdio>//头文件
using namespace std;//用命名空间std
const int MAXN = 1010;//定义常数
int a[MAXN];
int N;
int num[4];
int ans = 0;
int main()
{
    //freopen("sort3.in","r",stdin);
    //freopen("sort3.out","w",stdout);
    scanf("%d",&N);
    for(int i = 1;i <= N;i ++){
        scanf("%d",&a[i]);
        num[a[i]]++;
    }
    num[2] = num[1]+num[2];
    num[3] = num[1]+num[2]+num[3];
    for(int i = N; i > num[2]; i--){
        if(a[i] == 1){
            bool l = 1;
            for(int k = 1; k <= num[1]; k++)
                if(a[k] == 3){
                    swap(a[k],a[i]);
                    l = 0;ans++;
                    break;
                }
            if(l)
                for(int k = 1;k <= num[2]; k++){
                    if(a[k] != 1){
                        swap(a[k],a[i]);
                        ans++;
                        break;
                    }
                }
        }
        if(a[i] == 2){
            bool l = 1;
            for(int k = num[1]+1; k <= num[2]; k++)
                if(a[k] == 3){
                    swap(a[k],a[i]);
                    ans++;
                    l = 0;
                    break;
                }
            if(l)
                for(int k = 1; k <= num[1]; k++)
                    if(a[k] == 3){
                        ans ++;
                        swap(a[k],a[i]);
                        break;
                    }
        }
    }
    for(int i = num[2]; i >= num[1]+1; i--){
        if(a[i] == 1)
            for(int k = 1; k <= num[1]; k++)
                if(a[k] == 2){
                    swap(a[k],a[i]);
                    ans++;
                    break;
                }
    }
    printf("%d\n",ans);
    return 0;
}