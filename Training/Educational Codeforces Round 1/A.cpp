#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int _;
    ll ans,a,tmp;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&a);
        ans=(1+a)*a/2;
        tmp=1;
        while(tmp<=a)
        {
            ans-=2*tmp;
            tmp*=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
