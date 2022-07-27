//二维费用背包问题，费用分别为杀怪数和忍耐度
//每当经验值大于所需经验值时，就比较消耗的忍耐度，更新答案
#include <bits/stdc++.h>
using namespace std;
int dp[505][505];

int main()
{
    int n, m, k, s;
    int a, b;
    while (scanf("%d%d%d%d", &n, &m, &k, &s)!=EOF)
    {
        memset(dp, 0, sizeof(dp));
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < k; i++) {//怪的种数
            scanf("%d%d", &a, &b);
            for (int j = 1; j <= s; j++) {//杀怪数
                for (int k = b; k <= m; k++){//忍耐度
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - b] +a);
                    if (dp[j][k] >= n) {//大于等于所需经验值
                        ans = min(ans, k);//消耗的忍耐度越小越好
                    }
                }
            }
        }
        if ( ans< 0x3f3f3f3f)printf("%d\n",m-ans);
        else printf("-1\n");
    }
}
