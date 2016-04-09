#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll m=1000000007;
const ll mt=m-1;
ll  pow_mod(ll a,ll n)
{
    if(n==0) return 1;
    ll x=pow_mod(a,n/2);
    ll ans=(x%m)*(x%m);
    ans%=m;
    if(n%2==1) ans=ans*a%m;
    return ans;
}

ll fib(ll n,ll t1,ll t2)
{
    ll t[2][2]={1,1,1,0};
    ll p[2][2];
    ll a[2][2]={1,0,0,0};
    ll i,j,k;
    n--;
    while(n)
    {
        if(n%2==1)
        {
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
            {
                p[i][j]=a[i][j]%mt;
                a[i][j]=0;
            }
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    for(k=0;k<2;k++)
                        {
                            a[i][j]=a[i][j]+p[i][k]*t[k][j]%mt;
                            a[i][j]%=mt;
                        }
        }

        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
        {
            p[i][j]=t[i][j]%mt;
            t[i][j]=0;
        }

        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                    t[i][j]=(t[i][j]+p[i][k]*p[k][j]%mt)%mt;
        n=n>>1;
    }
    //printf("%lld %lld\n",a[0][0],a[0][1]);
    ll ans=pow_mod(t2,a[0][0])*pow_mod(t1,a[0][1]);
    return ans%m;
}

int main()
{
    ll a,b,n;
    while(~scanf("%lld%lld%lld",&a,&b,&n))
    {
        a%=m;
        b%=m;
        if(n==0) printf("%lld\n",a);
        else if(n==1) printf("%lld\n",b);
        else  printf("%lld\n",fib(n,a,b));
    }
    return 0;
}
