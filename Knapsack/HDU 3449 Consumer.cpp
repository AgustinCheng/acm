//有依赖的背包（简化），不用优化版代码会超时
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[100055];
int f[100055];
int main()
{
    int n,V,m,C,w,c;
    while (scanf("%d%d", &n, &V) != EOF) {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++)//枚举主件.
        {
            memcpy(g, f, sizeof(g));
            scanf("%d%d", &C, &m);
            for (int j = 0; j < m; j++)//枚举第i件物品的附件.
            {
                scanf("%d%d", &c, &w);
                for (int k = V - C; k >= c; k--)
                {
                    g[k] = max(g[k], g[k - c] + w);
                }
            }
            for (int j = C; j <= V; j++) f[j] = max(f[j], g[j - C]);
        }
        printf("%d\n", f[V]);
    }
}
