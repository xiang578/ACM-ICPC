#include<bits/stdc++.h>
using namespace std;
int a[1024],p[1024],dp[1024],sum[1024];

int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&p[i]);
        }
        sum[0]=sum[n+1]=0;
        for(int i=n;i>=1;i--)
            sum[i]=sum[i+1]+a[i];
        dp[n+1]=0;
        for(int i=1;i<=n;i++)
            dp[i]=0x3f3f3f3f;
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=i;j--)
            {
                dp[i]=min(dp[i],dp[j+1]+(sum[i]-sum[j+1]+10)*p[j]);
            }
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}
