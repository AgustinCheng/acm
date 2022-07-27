//先求出连通块，对每个连通块分别背包
//但是如果直接背包，时间与空间都不允许，所以采取暴搜+剪枝，并用优先队列模拟01背包行为
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 55
struct node
{
    int c,w;
} p[N];
vector<node> group[N];
struct Node
{
    int c,w;//时间，金钱
    bool operator<(const Node a)const
    {
        return w!=a.w?w<a.w:c>a.c;  //金钱从大到小，时间从小到大排列；
    }
} s;
int ans,cnt,v[N],n,m,mp[N][N];
void dfs(int c)//dfs找连通块,每个连通块分别放一个group里
{
    v[c]=1;
    group[cnt].push_back(p[c]);
    for(int i=1; i<=n; i++)
        if(!v[i]&&mp[c][i])
            dfs(i);
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(int i=1; i<=n; i++)
        {
            int k;
            scanf("%d%d%d",&p[i].c,&p[i].w,&k);
            while(k--)
            {
                int t;
                scanf("%d",&t);
                mp[i][t]=mp[t][i]=1;//两点可以互相到达
            }
        }
        //分组
        cnt=0;
        memset(v,0,sizeof(v));
        for(int i=1; i<=n; i++)
        {
            if(!v[i])
            {
                group[cnt].clear();
                dfs(i);
                cnt++;
            }
        }
        ans=INF;
        priority_queue<Node> q2;
        queue<Node>q1;
        for(int i=0; i<cnt; i++) //对每组做背包
        {
            while(!q1.empty())q1.pop();
            while(!q2.empty())q2.pop();
            s.c=s.w=0;
            q1.push(s);
            for(int j=0; j<group[i].size(); j++)
            {
                while(!q1.empty())//对每个状态都考虑第j个物品取不取
                {
                    s=q1.front();
                    q1.pop();
                    q2.push(s);//不选j的状态
                    s.c+=group[i][j].c;
                    s.w+=group[i][j].w;
                    if(s.w>=m)
                    {
                        ans=min(ans,s.c);//金钱已经饱和，时间越小越好
                        continue;//钱够多了，再加其他物品只会增加时间，剪枝
                    }
                    if(s.c>=ans)    continue;//时间比ans大(ans!=INF说明钱足够了，只用比时间），剪枝
                    q2.push(s);//选j的状态
                }
                int mincost=INF;
                while(!q2.empty())// 滚动数组
                {
                    s=q2.top();
                    q2.pop();
                    if(s.c<mincost)//q2金钱多的先出队列，后出的金钱少，如果后出的时间还太长，直接去掉
                        q1.push(s),mincost=s.c;
                }
            }
        }
        printf("Case %d: ",++kase);
        if(ans==INF)    printf("Poor Magina, you can't save the world all the time!\n");
        else    printf("%d\n",ans);
    }
}
