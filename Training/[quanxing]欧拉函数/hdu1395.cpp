#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int LL;
int euler_phi(int n)
{
    int m=(int)sqrt(n+0.5);
    int ans=n;
    for(ll i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int pow_mod(LL a,LL n,int m)
{
    if(n==0) return 1;
    LL x=pow_mod(a,n/2,m);
    LL ans=x*x%m;
    ans=ans%m;
    if(n%2==1) ans=ans*a%m;
    return (int)ans;
}

int main()
{
    int n,t,ans,m,j,e[1024];
    while(~scanf("%d",&n))
    {
        if(n==1||n%2==0) printf("2^? mod %d = 1\n",n);
        else
        {
            m=euler_phi(n);
            j=0;
            for(int i=2; i*i<=m; i++)
            {
                if(m%i==0)
                {
                    e[j]=i;
                    j++;
                    if(i*i!=m)
                    {
                        e[j]=m/i;
                        j++;
                    }
                }
            }
            e[j]=m;
            sort(e,e+j);
            for(int i=0;i<=j;i++)
            {
                if(pow_mod(2,e[i],n)==1)
                {
                    ans=e[i];
                    break;
                }
            }
            printf("2^%d mod %d = 1\n",ans,n);
        }
    }
    return 0;
}
