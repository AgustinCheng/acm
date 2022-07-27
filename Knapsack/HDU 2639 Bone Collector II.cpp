//第k优解模板题
#include <bits/stdc++.h>
using namespace std;
int f[1005][32];
int w[105], c[105];
int a[100], b[100];
int main()
{
    int t;
    scanf("%d", &t);
    int n, V, k;
    while(t--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d%d", &n, &V, &k);
        for (int i = 1; i <= n; i++)scanf("%d", &w[i]);
        for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = V; j >= c[i]; j--) {
                for (int l = 1; l <= k; l++) {//生成两个有序队列
                    a[l] = f[j][l];
                    b[l] = f[j - c[i]][l] + w[i];
                }
                a[k + 1] = -1;
                b[k + 1] = -1;
                int x = 1, y = 1, o = 1;//合并两个有序队列
                while (o != k + 1 && (a[x] != -1 || b[y] != -1)) {
                    if (a[x] > b[y]) f[j][o] = a[x], x++;
                    else f[j][o] = b[y], y++;
                    if (f[j][o] != f[j][o - 1]) o++;
                }
            }
        }
        printf("%d\n", f[V][k]);
    }
}
