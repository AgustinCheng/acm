//��ά���ñ������⣬���÷ֱ�Ϊɱ���������Ͷ�
//ÿ������ֵ�������辭��ֵʱ���ͱȽ����ĵ����Ͷȣ����´�
#include <bits/stdc++.h>
using namespace std;
int dp[505][505];

int main()
{
    int n, m, k, s;
    int a, b;
    while (scanf("%d%d%d%d", &n, &m, &k, &s)!=EOF)
    {
        memset(dp, 0, sizeof(dp));
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < k; i++) {//�ֵ�����
            scanf("%d%d", &a, &b);
            for (int j = 1; j <= s; j++) {//ɱ����
                for (int k = b; k <= m; k++){//���Ͷ�
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - b] +a);
                    if (dp[j][k] >= n) {//���ڵ������辭��ֵ
                        ans = min(ans, k);//���ĵ����Ͷ�ԽСԽ��
                    }
                }
            }
        }
        if ( ans< 0x3f3f3f3f)printf("%d\n",m-ans);
        else printf("-1\n");
    }
}
