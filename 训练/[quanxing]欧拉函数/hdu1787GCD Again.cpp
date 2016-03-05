#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
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
        printf("%lld\n",n-1-euler_phi(n));
    }
    return 0;
}
