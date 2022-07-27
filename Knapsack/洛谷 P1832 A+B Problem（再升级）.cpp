//相当于把若干个素数塞进最大容量为n背包里，且恰好塞满，求总方案数
//因为素数可以重复出现，所以是完全背包
#include <bits/stdc++.h>
using namespace std;
long long dp[1004];
const int maxn = 1e3 + 10;
int cnt = 0;
vector<int> primes;
bool judge[maxn];
int main()
{
    //欧拉筛
    int i, j;
    memset(judge, true, sizeof(judge));
    judge[0] = false; judge[1] = false;
    for (i = 2; i < maxn; i++)
    {
        if (judge[i])
        {
            primes.push_back(i);
            cnt++;
        }
        for (j = 0; j < cnt && i * primes[j] < maxn; j++)
        {
            judge[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
    //完全背包
    int n;
    dp[0] = 1;
    scanf("%d", &n);
    vector<int>::iterator it;
    for (it = primes.begin(); it != primes.end(); it++)//遍历
    {
        for (int j = *it; j <= n; j++)
        {
            dp[j] += dp[j - *it];
        }
    }
    printf("%lld", dp[n]);
    return 0;

}
