//分组背包模板题
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[105];
int c[105], w[105];
int main()
{
	int N, V;
	int s;
	memset(f, 0, sizeof(f));
	scanf("%d%d", &N, &V);
	for (int i = 0; i < N; i++) {
		scanf("%d", &s);
		for (int j = 0; j < s; j++)
		{
			scanf("%d%d", &c[j], &w[j]);
		}
		for (int v = V; v >= 0; v--)
		{
			for (int j = 0; j < s; j++)
			{

				if (v - c[j] >= 0)f[v] = max(f[v], f[v - c[j]] + w[j]);
			}
		}
	}
	printf("%d\n", f[V]);
}
