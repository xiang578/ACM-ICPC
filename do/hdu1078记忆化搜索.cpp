#include<bits/stdc++.h>
using namespace std;
int n,k,a[120][120],dp[120][120];
int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};

int dfs(int x,int y)
{
    if(dp[x][y]>0) return dp[x][y];
    int ans=0;
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<=k; j++)
        {
            int tx=dx[i]*j+x;
            int ty=dy[i]*j+y;
            if(tx<0||tx>=n||ty<0||ty>=n) continue;
            if(a[tx][ty]<=a[x][y]) continue;
            ans=max(ans,dfs(tx,ty));
        }
    }
    dp[x][y]=ans+a[x][y];
    //printf("%d %d %d\n",x,y,dp[x][y]);
    return dp[x][y];
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1) break;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        memset(dp,0xff,sizeof(dp));
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
