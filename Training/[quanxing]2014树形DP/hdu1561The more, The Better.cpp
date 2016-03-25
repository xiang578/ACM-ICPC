#include<bits/stdc++.h>
using namespace std;
int n,m,w[300],dp[300][300];
vector<int>v[300];

void dfs(int x)
{
    int y,i,j,k;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        dfs(y);
        for(j=m+1;j>1;j--)
        {
            for(k=1;k<j;k++)
            dp[x][j]=max(dp[x][j],dp[x][k]+dp[y][j-k]);
        }
    }
}
int main()
{
    int i,j,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0;i<=n;i++)
        {
            v[i].clear();
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(i);
            for(j=1;j<=m+1;j++)
                dp[i][j]=b;
        }
        dfs(0);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
