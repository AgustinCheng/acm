//多重背包变形，纯暴力
#include <bits/stdc++.h>
using namespace std;
int dp[40005];
int w[10] = { 0,1, 2, 3, 5, 10, 20 };
int m[10];
int main()
{
	for (int i = 1; i <= 6; i++)scanf("%d", &m[i]);
	dp[0] = 1;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=m[i];j++)
			for (int k = 1000; k >= 0; k--)
			{
				if (dp[k]) { dp[k + w[i]] = 1; }//关键代码
			}
	int ans = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (dp[i])ans++;
	}
	printf("Total=%d", ans);
}
