#include<bits/stdc++.h>
using namespace std;
int sum,n,h[1000],dp[2][5000];

int main()
{
    while(~scanf("%d",&n))
    {
        sum=0;
        memset(dp,0xff,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            sum+=h[i];
        }
        int now=0;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            now=now^1;
            for(int j=0;j<=sum;j++)
            {
                dp[now][j]=dp[now^1][j];
            }

            for(int j=0;j<=sum;j++)
            {
                if(dp[now^1][j]!=-1)
                    dp[now][j+h[i]]=max(dp[now][j+h[i]],dp[now^1][j]+h[i]);

                if(j<=h[i]&&dp[now^1][j]!=-1)
                    dp[now][h[i]-j]=max(dp[now][h[i]-j],dp[now^1][j]-j+h[i]);

                if(j>h[i]&&dp[now^1][j]!=-1)
                    dp[now][j-h[i]]=max(dp[now][j-h[i]],dp[now^1][j]);
            }

            //for(int j=0;j<=sum;j++) printf("%d ",dp[now][j]);printf("\n");

        }
        if(dp[now][0]<=0) puts("Impossible");
        else printf("%d\n",dp[now][0]);
    }
    return 0;
}
