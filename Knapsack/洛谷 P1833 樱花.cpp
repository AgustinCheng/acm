//混合背包模板题
#include <bits/stdc++.h>
using namespace std;
long long dp[5005];
int main()
{
	int n;
	int s1,s2,s3,s4;
	char ch;
	cin >> s1 >>ch>> s2>>s3>>ch>>s4;
	int t = (s3 - s1) * 60 + s4 - s2;
	cin >> n;
	int cost, v, m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &cost, &v, &m);
		if (m == 0)
		{
			for (int j = cost; j <= t; j++)
			{
				dp[j] = max(dp[j], dp[j - cost] + v);
			}
		}
		else if (m == 1)
		{
			for (int j = t; j >= cost; j--)
			{
				dp[j] = max(dp[j], dp[j - cost] + v);
			}
		}
		else
		{
			int num = 1;
			while (num < m)
			{
				for (int j = t; j >= cost*num; j--)
				{
					dp[j] = max(dp[j], dp[j - cost*num] + v*num);
				}
				m -= num;
				num <<= 1;
			}
			if (m>0)
			{
				for (int j = t; j >= cost * m; j--)
				{
					dp[j] = max(dp[j], dp[j - cost * m] + v * m);
				}
			}
		}
	}
	printf("%lld\n", dp[t]);
}
