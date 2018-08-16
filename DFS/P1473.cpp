#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[10];
int b[10];
int f[10];
int z[10];

bool run(int n)
{
    memset(f, 0, sizeof(f));
    int p = 1;
    f[p] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            f[p] = f[p] * 10 + i + 1;
        }
        else
        {
            z[p] = a[i];
            p++;
            f[p] = f[p] * 10 + i + 1;
        }
    }
    int ans = f[1];
    /*
    for(int i=1;i<=p;i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;
    system("pause");*/
    for (int i = 1; i < p; i++)
    {
        if (z[i] == 1)
        {
            ans += f[i + 1];
        }
        else
        {
            ans -= f[i + 1];
        }
        //cout<<ans<<endl;
    }
    if (ans == 0)return 1;
    else return 0;
}

void dfs(int v, int x)
{
    if (v == x)
    {
        if (run(x))
        {
            cout << 1;
            for (int i = 1; i <= x; i++)
            {
                if (a[i] == 1)cout << "+" << i + 1;
                if (a[i] == 0)cout << " " << i + 1;
                if (a[i] == 2)cout << "-" << i + 1;
            }
            cout << endl;
        }
        return ;
    }
    for (int i = 0; i <= 2; i++)
    {
        a[v + 1] = i;
        dfs(v + 1, x);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 2; i++)
    {
        a[1] = i;
        dfs(1, n - 1);
    }
    return 0;
}

