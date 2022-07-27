//完全背包的模板+n次循环求解，不断更新资产就行
#include <bits/stdc++.h>
using namespace std;
int dp[100005], cost[15], v[15];
int main()
{
	int s, n, d;
	scanf("%d%d%d", &s, &n, &d);
	for (int i = 1; i <= d; i++)
	{
		scanf("%d%d", &cost[i], &v[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= d; j++)
			for (int k = cost[j]/1000; k <= s/1000; k++)
			{
				dp[k] = max(dp[k], dp[k - cost[j]/1000] + v[j]);
			}
		s = s + dp[s/1000];

	}
	printf("%d\n", s);
}
