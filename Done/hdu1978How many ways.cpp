#include<bits/stdc++.h>
using namespace std;
const int mod=10000;
int g[120][120],n,m,ans[120][120],vis[120][120];

/*void dfs(int x,int y,int cnt,int sum)
{
    if(cnt==0) return ;
    if(x+1<=n)
    {
        if(!vis[x+1][y]) ans[x+1][y]+=sum;
        vis[x+1][y]=1;
        ans[x+1][y]%=mod;
        dfs(x+1,y,cnt-1,sum);
    }

    if(y+1<=m)
    {
        if(!vis[x][y+1]) ans[x][y+1]+=sum;
        vis[x][y+1]=1;
        ans[x][y+1]%=mod;
        dfs(x,y+1,cnt-1,sum);
    }
}*/

void get(int x,int y,int cnt,int sum)
{
    int i,j,k=cnt;
    for(j=0;j<=k;j++)
    {
        for(i=0;i<=cnt;i++)
        {
            if(i==0&&j==0) continue;
            ans[x+j][y+i]+=sum;
            ans[x+j][y+i]%=mod;
        }
        cnt--;
    }
}

int main()
{
    int _,i,j;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        ans[1][1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(ans[i][j]==0) continue;
                //dfs(i,j,g[i][j],ans[i][j]);
                get(i,j,g[i][j],ans[i][j]);
            }
        }
        printf("%d\n",ans[n][m]%mod);
    }
    return 0;
}
