//完全背包模板题
#include<bits/stdc++.h>
using namespace std;
long long f[10000005];
int c[10005],w[10005];
int t,m;
int main()
{
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {

        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=c[i];j<=t;j++)
        {
            f[j]=max(f[j],f[j-c[i]]+w[i]);
        }
    }
    printf("%lld\n",f[t]);
}
