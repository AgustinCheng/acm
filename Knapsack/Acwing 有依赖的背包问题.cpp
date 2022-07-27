//�������ı���,h[x],ne[x]��������ö��ĳ���������ӽڵ�
#include <bits/stdc++.h>
using namespace std;
const int N =1005;
int e[N],w[N],v[N],ne[N],h[N],idx;
int dp[105][105];
int n,m;
void init()
{
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int son=e[i];
        dfs(son);//�ݹ����
        for(int j=m;j>=0;j--)//����son�����Ʒ�飬���ֻѡһ���������Ƚ������ѭ��
        {
            for(int k=0;k<=j;k++)
                dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[son][k]);
        }
    }
    for(int i=m;i>=0;i--)
        if(i>=v[x])
            dp[x][i]=dp[x][i-v[x]]+w[x];
        else          //ע�⣬���ڵ㲻ѡ�Ļ����ӽڵ�һ��������ѡ
            dp[x][i]=0;

}
int main()
{
    init();
    int root;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int fa;
        scanf("%d%d%d",&v[i],&w[i],&fa);
        if(fa==-1)
            root=i;
        else
            add(fa,i);
    }
    dfs(root);
    cout<<dp[root][m]<<endl;
    return 0;
}
