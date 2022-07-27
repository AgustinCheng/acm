//关键是看出这个是分组背包，一天只能选一门课
#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;
int f[1005];
int w[1005][1005];
int main()
{
    int N, V;
    while (scanf("%d%d", &N, &V) != EOF && (N || V)) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= V; j++) {
                scanf("%d", &w[i][j]);
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int v = V; v >= 0; v--) {
                for (int j = 1; j <= V; j++) {
                    if (v - j >= 0)f[v] = max(f[v], f[v - j] + w[i][j]);
                }
            }
        }
        printf("%d\n", f[V]);
    }
}
