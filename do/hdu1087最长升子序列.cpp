#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1024],dp[1024];

int main()
{
    int i,j,n;
    ll ans;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        memset(dp,0,sizeof(dp));
        a[0]=0;
        ans=dp[1]=a[1];
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
            }
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
