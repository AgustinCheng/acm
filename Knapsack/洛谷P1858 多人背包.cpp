//第k优解坑题
//如果理解模板代码自然不成问题
//模板中每个解的价值都不相同，但此题只要求方案不同
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[6005][201];
ll w[301], c[301];
ll a[201], b[201];
int main()
{
    ll n, V, k;
    memset(f, ~0x3f3f3f3f, sizeof(f));
    f[0][1] = 0;
    scanf("%lld%lld%lld", &k, &V, &n);
    for (ll i = 1; i <= n; i++)scanf("%lld%lld",&c[i],&w[i]);
        for (ll i = 1; i <= n; i++) {
            for (ll j = V; j >= c[i]; j--) {
                for (ll l = 1; l <= k; l++) {
                    a[l] = f[j][l];
                    b[l] = f[j - c[i]][l] + w[i];
                }
            a[k + 1] = -1;
            b[k + 1] = -1;
            ll x = 1, y = 1, o = 1;
            while (o != k + 1 && (a[x] != -1 || b[y] != -1)) {
                if (a[x] > b[y]) f[j][o] = a[x], x++;
                else f[j][o] = b[y], y++;
                o++;//if (f[j][o] != f[j][o - 1]) o++;
                //因为题意偏差，需要对模板这里进行修改，
            }
        }
    }
    ll sum = 0;
    for (ll i = 1; i <= k; i++)
        sum += f[V][i];
    printf("%lld\n", sum);
    return 0;
}
