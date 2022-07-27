//多重背包，略微改一下状态转移方程就行了
#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long n, m, k[N], c[N], qm, dp[N] = { 1 }, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        qm += c[i] * k[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = qm; j >= 0; j--) {
            for (int x = 0; x <= k[i] && x * c[i] <= j; x++) {
                dp[j] = max(dp[j], dp[j - x * c[i]] * x);
            }
        }
    }
    while (ans <= qm && dp[ans] < m) ans++;
    cout << ans << endl;
    return 0;
}
