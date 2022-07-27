//二维费用背包模板题
#include <bits/stdc++.h>
using namespace std;
int dp[505][505];

int main()
{
	int N, V, M;
	scanf("%d%d%d",&V, &M,&N);
	int v, m, w;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &v, &m, &w);
		for (int j = V; j >= v; j--) {
			for (int k = M; k >= m; k--) {
				dp[j][k] = max(dp[j - v][k - m] + w, dp[j][k]);
			}
		}
	}
	printf("%d", dp[V][M]);
}
