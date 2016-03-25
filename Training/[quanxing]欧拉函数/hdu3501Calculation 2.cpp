#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll n,i;

ll euler_phi(ll n)
{
    ll m=(int)sqrt(n+0.5);
    ll ans=n;
    for(ll i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int main()
{

    while(~scanf("%lld",&n)&&n)
    {
        if(n<=3) printf("0\n");
        else
        {
            ll ans=(1+n)*n/2-1-n;
            ans=(ans-n*euler_phi(n)/2+1)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
