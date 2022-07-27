//分组背包，可以用vector存储数据
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1005];
int c[1005], w[1005];
vector<int> zu[1005];
int main()
{
	int N, V;
	int s;
	scanf("%d%d", &V, &N);
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &c[i],&w[i],&s);
		zu[s].push_back(i);
		if (s>maxx)maxx = s;
	}
	for (int i = 1; i <= maxx; i++) {
		for (int v = V; v >= 0; v--) {
			for (int j = 0; j < zu[i].size(); j++) {
				if (v - c[zu[i][j]] >= 0)f[v] = max(f[v], f[v - c[zu[i][j]]] + w[zu[i][j]]);
			}
		}
	}
	printf("%d\n", f[V]);
}
