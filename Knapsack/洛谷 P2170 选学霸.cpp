//用并查集标记实力相当的人，他们要么一起被选，要么一起不被选，可以看作一个泛化物品
//建议开02优化
#include <bits/stdc++.h>
using namespace std;
int dp[100002], w[100002];
int fa[100002], ra[100002];
int g[100002];
//并查集模板
void init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
		ra[i] = 1;
	}
}
int find(int x)
{
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
	int x = find(i), y = find(j);
	if (x != y)
	{
		if (ra[x] <= ra[y])
		{
			fa[x] = y;
			ra[y] += ra[x];
	    }
		else
		{
			fa[y] = x;
			ra[x] += ra[y];
		}
	}
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	init(n);
	int a, b;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d%d", &a, &b);
		merge(a, b);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i)
		{
			g[++cnt] = ra[i];
		}
	}
	int minn = min(2 * m, n);
	for(register int i=1;i<=cnt;i++)
		for (register int j = minn; j >= g[i]; j--)
		{
			if (abs(dp[j] - m) > abs(dp[j - g[i]]+g[i] - m))
				dp[j] = dp[j - g[i]]+g[i];
		}
	int mi = 0x3f3f3f3f;
	for(int i=1;i<=minn;i++)
		if (abs(m - dp[i]) < abs(m - mi)) mi = dp[i];
	if (mi == 0x3f3f3f3f)printf("0\n");
	else printf("%d\n", mi);
}
