#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,a,b,c[2048],n;
int cnt;

ll gcd(ll u,ll v)
{
    return v==0?u:gcd(v,u%v);
}

void dfs(int cur,ll lcm,int num)
{
    lcm=c[cur]/gcd(c[cur],lcm)*lcm;
    //printf("%lld\n",lcm);
    if(num%2==1) ans+=(b/lcm-(a-1)/lcm);
    else ans-=(b/lcm-(a-1)/lcm);

    for(int i=cur+1;i<cnt;i++)
        dfs(i,lcm,num+1);
}

int main()
{
    ll i;
    int _,k,j;
    scanf("%d",&_);
    for(k=1; k<=_; k++)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        memset(c,0,sizeof(c));
        ans=cnt=0;
        for(i=2;i*i<=n&&n>1;i++)
        {
            while(n%i==0)
            {
                c[cnt++]=i;
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1) c[cnt++]=n;
        for(j=0; j<cnt; j++)
            dfs(j,c[j],1);
        ans=b-a+1-ans;
        printf("Case #%d: %lld\n",k,ans);
    }
    return 0;
}
