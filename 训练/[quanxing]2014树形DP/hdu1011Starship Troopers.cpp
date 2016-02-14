#include<bits/stdc++.h>
using namespace std;

int c[1024],w[1024],dp[1024][1024],n,m,vis[1024];
vector<int>v[1024];

int get(int x)
{
    int i;
    for(i=0;;i++)
        if(i*20>=x) break;
    return i;
}

void dfs(int x)
{
    int y,i,j,k;
    vis[x]=1;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(vis[y]) continue;
        dfs(y);
        for(j=m;j>=c[x];j--)
        {
            for(k=1;k<=j-c[x];k++)
                dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[y][k]);
        }
    }
}

int main()
{
    int i,j,t,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<=n;i++)
            v[i].clear();
        if(n==-1&&m==-1) break;
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&t,&w[i]);
            c[i]=get(t);
            for(j=c[i];j<=m;j++)
                dp[i][j]=w[i];
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(m==0) {puts("0");continue;}
        dfs(1);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
