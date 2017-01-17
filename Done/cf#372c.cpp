#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll ans[N];

ll get(ll x)
{
    ll l=1;
    ll r=x;
    ll ret=x*(x+1);
    while(l<=r)
    {
        ll m=(l+r)/2;
        ll t=m*(x+1);
        ll e=__gcd(t,x);
        ll y=x/e;
        ll f=__gcd(t,y);
        ll z=y/f;
        if(z==1)
        {
            r=m-1;
            ret=t;
        }
        else
        {
            l=m+1;
        }
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    ans[1]=2;
    ll now=2;
    for(ll i=2; i<=n; i++)
    {
        ll k=get(i);
        ll e=__gcd(k,i);
        ll j=i/e;
        ans[i]=(k/e)*(k/j)-now/i;
        now=k;
    }
    for(int i=1; i<=n; i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
