#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000+5],dp[1000000+5],use[1000000+5];

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
        memset(use,0xff,sizeof(use));
        ans=0;
        use[0]=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(use[j]==-1||use[j]==i) break;
                dp[j+1]

            }
            ans=max(ans,dp[m]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
