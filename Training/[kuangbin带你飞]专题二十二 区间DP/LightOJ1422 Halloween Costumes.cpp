#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int dp[120][120],a[120];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j,k,t,n,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));

        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                dp[i][j]=j-i+1;

        for(i=n-1;i>=1;i--)
        {
            for(j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(k=i+1;k<=j;k++)
                    {
                        if(a[i]==a[k])
                            dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
                    }
            }
        }
        printf("Case %d: %d\n",++cas,dp[1][n]);
    }
    return 0;
}
