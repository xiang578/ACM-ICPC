#include<bits/stdc++.h>
using namespace std;
int mp[1024][1024],dp[1024],vis[1024],m;
vector<int>v[1024];
const int inf=0x7fffffff;

void dfs(int x,int fa)
{
    int y,i,tmp=0,f=0;
    dp[x]=mp[fa][x];
    vis[x]=1;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        //printf("  %d %d\n",x,y);
        if(vis[y]) continue;
        dfs(y,x);
        f=1;
        tmp+=dp[y];
     }
     if(!f) tmp=dp[x];
     dp[x]=min(dp[x],tmp);
     //printf("%d\n",x);
}
int main()
{
    int i,j,n,a,b,w;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++)
            v[i].clear();
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                mp[i][j]=inf;
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back(b);
            v[b].push_back(a);
            mp[a][b]=mp[b][a]=w;
        }
        memset(vis,0,sizeof(vis));
        dfs(m,m);
        printf("%d\n",dp[m]);
    }
    return 0;
}
