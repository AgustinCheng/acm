//有依赖的背包（简化）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> belong[65];
int w[65], c[65];
int g[3205];
int f[3205];
int main()
{
    memset(f, 0, sizeof f);
    int V, M;
    scanf("%d%d", &V, &M);
    V = V / 10;
    int v, p, q;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d", &v, &p, &q);
        c[i] = v / 10;
        w[i] = p;
        belong[q].push_back(i);
    }
    for (int l = 0; l < belong[0].size(); l++)
    {
        int i = belong[0][l];
        memcpy(g, f, sizeof(g));
        for (int j = 0; j < belong[i].size(); j++)
        {
            for (int k = V - c[i]; k >= c[belong[i][j]]; k--)
            {
                g[k] = max(g[k], g[k - c[belong[i][j]]] + c[belong[i][j]] * w[belong[i][j]]);
            }
        }
        for (int j = c[i]; j <= V; j++) f[j] = max(f[j], g[j - c[i]]+c[i]*w[i]);
    }
    printf("%d", f[V] * 10);
}
