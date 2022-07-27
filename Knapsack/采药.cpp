#include<cstdio>
#include<iostream>
using namespace std;
int f[1005], c[105], w[105];
int sum[105];
int V, N;
int main()
{
    scanf("%d%d", &V, &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", &c[i], &w[i]);
    }
    for (int i = N; i > 0; i--)
        sum[i] = sum[i + 1] + w[i];
    for (int i = 1; i <= N; i++)
    {
        int bound = max(V - sum[i], c[i]);//sum[i]=sum{w[i~n]}
        for (int j = V; j >= bound; j--)
        {
            f[j] = max(f[j], f[j - c[i]] + w[i]);
        }
    }
    printf("%d\n", f[V]);
}

