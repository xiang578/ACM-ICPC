#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,c[123456],a[123456],sum[123456];
const ll m=1e9+7;

int main()
{
    int _,i,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        c[0]=1;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            c[i]=c[i-1]*2%m;
        }
        ans=0;
        memset(sum,0,sizeof(sum));
        sum[a[1]]=1;
        for(i=2;i<=n;i++)
        {
            ans=(ans+c[i-2])%m;
            ans=(ans-sum[a[i]]+m)%m;
            sum[a[i]]=(sum[a[i]]+c[i-2])%m;
            ans=ans*2%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
