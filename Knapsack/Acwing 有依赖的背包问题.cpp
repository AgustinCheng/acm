//有依赖的背包,h[x],ne[x]用于依次枚举某结点的所有子节点
#include <bits/stdc++.h>
using namespace std;
const int N =1005;
int e[N],w[N],v[N],ne[N],h[N],idx;
int dp[105][105];
int n,m;
void init()
{
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int son=e[i];
        dfs(son);//递归求解
        for(int j=m;j>=0;j--)//对于son这个物品组，最多只选一个，所以先进行这层循环
        {
            for(int k=0;k<=j;k++)
                dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[son][k]);
        }
    }
    for(int i=m;i>=0;i--)
        if(i>=v[x])
            dp[x][i]=dp[x][i-v[x]]+w[x];
        else          //注意，父节点不选的话，子节点一个都不能选
            dp[x][i]=0;

}
int main()
{
    init();
    int root;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int fa;
        scanf("%d%d%d",&v[i],&w[i],&fa);
        if(fa==-1)
            root=i;
        else
            add(fa,i);
    }
    dfs(root);
    cout<<dp[root][m]<<endl;
    return 0;
}
