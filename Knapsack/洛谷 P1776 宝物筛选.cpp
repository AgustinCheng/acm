//多重背包模板题
#include <bits/stdc++.h>
using namespace std;
int dp[40005],cost[105],v[105],m[105];
int main()
{
	int n, w;
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &v[i], &cost[i], &m[i]);
	for (int i = 1; i <= n; i++)
	{
		int k = 1;
		int amount = m[i];
		while (amount > k)
		{
			for (int j = w; j >= cost[i]*k; j--)
			{
				dp[j] = max(dp[j], dp[j - cost[i] * k] + v[i] * k);
			}
			amount -= k;
			k <<= 1;
		}
		if (amount > 0)
		{
			for(int j = w; j >= cost[i] * amount; j--)
			{
				dp[j] = max(dp[j], dp[j - cost[i] * amount] + v[i] * amount);
			}
		}
	}
	printf("%d\n", dp[w]);
}
