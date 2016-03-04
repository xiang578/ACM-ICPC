#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3fffffff;
ll a[1000000+5],dp[1000000+5],pre[1000000+5];

int main()
{
    int t,i,j,n,m;
    ll ans;
    while(~scanf("%d",&m))
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%lld",a+i);
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=m;i++)
        {
            ans=-inf;
            for(j=i;j<=n;j++)
            {
                dp[j]=max(dp[j-1]+a[j],pre[j]+a[j]);
                pre[j]=ans;
                ans=max(ans,dp[j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
