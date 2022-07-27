//先多重背包，再处理奇货
//建议开o2优化
#include <bits/stdc++.h>
using namespace std;
long long dp[10005];
struct q
{
	int pos, value;
}que[10005];
int n, m, C;
int main()
{
	scanf("%d%d%d", &n, &m, &C);
	long long v, w, d;
	//多重背包，单调队列优化
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld%lld", &v, &w, &d);
		for (int mo = 0; mo < v; mo++)//枚举余数
		{
			for (int k = 0, head = 0, tail = 0; k <= (C - mo) / v; k++)
			{
				int y = dp[k * v + mo] - k * w;
				while (head < tail && que[head].pos < k - d)head++;//限制长度
				while (head < tail && que[tail - 1].value <= y)tail--;
				que[tail].value = y, que[tail].pos = k;
				tail++;
				dp[k * v + mo] = que[head].value + k * w;
			}
		}
	}
	//奇货
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld%lld", &v, &w, &d);
		for (int j = C; j >= 0; j--)
		{
			for (int x = 0; x <= j; x++)
                dp[j] = (dp[j] > dp[j - x] + v * x * x + w * x + d) ? dp[j] : (dp[j - x] + v * x * x + w * x + d);
		}
	}
    printf("%lld", dp[C]);
}
