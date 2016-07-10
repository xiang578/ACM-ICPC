#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get(ll x)
{
    ll ret=0;
    for(ll i=2;i*i*i<=x;i++)
    {
        ll tmp=i*i*i;
        ret+=x/tmp;
    }
    return ret;
}
int main()
{
    ll m,l,r,mid,ans=-1,cnt;
    scanf("%lld",&m);
    l=1;r=1e16;
    while(l<=r)
    {
        mid=(r-l)/2+l;
        cnt=get(mid);
        if(cnt==m)
        {
            ans=mid;
            r=mid-1;
        }
        else if(cnt>m)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
