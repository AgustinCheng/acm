//01背包简单变形
#include <bits/stdc++.h>
using namespace std;

int dp[30005], v[30],cost[30];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &cost[i], &v[i]);
		v[i] = cost[i] * v[i];
	}
	for(int i=1;i<=m;i++)
		for (int j = n; j >= cost[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - cost[i]] + v[i]);
		}
	printf("%d\n", dp[n]);
}
