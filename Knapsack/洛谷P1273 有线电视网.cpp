//有依赖的背包,vector写法
//dp[x][j]表示在以x为根的子树中，选择j个客户所能获得的最大收益
//最后遍历，比较dp[1][j]的最大收益是否亏本，更新最优解。
#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
vector<int> t[N];
int dp[N][N],w[N],v[N];
int n, m;
int dfs(int x)
{
    if (x > n - m) {
        dp[x][1] = w[x];
        return 1;
    }
    int sum = 0, num;
    for (int i = 0; i <t[x].size(); i++ )
    {
        int son = t[x][i];
        num = dfs(son); sum += num;
        for (int j = sum; j > 0; j--)
        {
            for (int k = 1; k <= num; k++)
                if(j-k>=0)dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[son][k]-v[son]);
        }
    }
    return sum;
}
int main()
{
    memset(dp,~0x3f3f3f3f, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <=n -m ; i++)
    {
        int k,node,c;
        scanf("%d", &k);
        while (k--) {
            scanf("%d%d", &node, &c);
            t[i].push_back(node);
            v[node] = c;
        }
    }
    for (int i = n-m+1; i <= n; i++)scanf("%d", &w[i]);
    dfs(1);

    for (int i = m; i >= 1; i--)
    {
        if (dp[1][i] >= 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
