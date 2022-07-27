//用01背包先求出总方案数，然后分别减去选这个物品的方案数，结果mod 10
#include <bits/stdc++.h>
using namespace std;
int dp[2002], w[2002], g[2002];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &w[i]);
	dp[0] = 1;
	//先求出总方案数
	for (int i = 0; i < n; i++)
		for (int j = m; j >= w[i]; j--)
		{
			dp[j] += dp[j - w[i]]%10;
		}

	for (int i = 0; i < n; i++)
	{
		memcpy(g, dp, sizeof dp);
		for (int j = w[i]; j <= m; j++)
		{
			g[j] -= g[j - w[i]] % 10;//减去选这个物品的方案数
		}
		for (int j = 1; j <= m; j++)
		{
			printf("%lld", (g[j]+10)%10);
		}
		printf("\n");

	}
}
