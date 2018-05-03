#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

double p[1024][1024],dp[1024][10];
int n,m,u[1024][10];

int main()
{
    while(~scanf("%d",&m))
    {
        if(m==-1) break;
        n=1<<m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }
        for(int i=0;i<=m;i++)
        {
            int cnt=0,now=1,t=1<<i;
            for(int j=1;j<=n;j++)
            {
                u[j][i]=now;
                cnt++;
                if(cnt%t==0) now++;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int t=1;t<=m;t++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j) continue;

                    if(u[i][t]==u[j][t]&&u[i][t-1]!=u[j][t-1])
                    {
                        //printf("%d %d %d\n",i,j,t);
                        dp[i][t]+=dp[i][t-1]*dp[j][t-1]*p[i][j];
                    }
                }
            }
        }
        int ans=1;
        double mx=dp[1][m];
        for(int i=1;i<=n;i++)
        {
            if(dp[i][m]>mx)
            {
                mx=dp[i][m];
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
