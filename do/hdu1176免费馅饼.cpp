#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int dp[N][11],a[N][11];

int main()
{
    int i,j,x,t,ans,n,up;
    while(~scanf("%d",&n)&&n)
    {
        memset(dp,0xff,sizeof(dp));
        memset(a,0,sizeof(a));
        up=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            a[t][x]++;
            up=max(up,t);
        }
        dp[0][5]=0;
        ans=0;
        for(i=0;i<up;i++)
        {
            for(j=0;j<=10;j++)
            {
                if(dp[i][j]==-1) continue;
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
                if(j>=1) dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+a[i+1][j-1]);
                if(j<10) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
            }
        }
        for(i=0;i<=10;i++)
        {
            ans=max(ans,dp[up][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
