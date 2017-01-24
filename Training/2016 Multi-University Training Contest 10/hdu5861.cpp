#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int N=1e5;
ll d[N],a[N],r[N],b[N],dp[N][120];
int _,n,k;
int get1(ll dis,int up)
{
    if(dis<=0) return 0;
    int l=1,r=up,ans=up;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(d[m]>dis)
        {
            r=m-1;
            ans=m;
        }
        else
        {
           l=m+1;
        }
    }
    return ans;
}

int get2(ll dis,int up)
{
    if(dis>=d[n]) return n;
    int l=up,r=n,ans=up;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(d[m]>dis)
        {
            r=m-1;
        }
        else
        {
            ans=m;
            l=m+1;
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        d[0]=0;
        d[1]=0;
        for(int i=2;i<=n;i++)
        {
            ll t;
            scanf("%lld",&t);
            d[i]=d[i-1]+t;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i],&r[i],&b[i]);
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                dp[i][j]=inf;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0]+a[i];
        }
        for(int j=1;j<=k;j++)
        {
            for(int i=1;i<=n;i++)
            {
                dp[i][j]=min(dp[i-1][j]+b[i],dp[i][j]);
                int x=get1(d[i]-r[i],i);
                int y=get2(d[i]+r[i],i);
                dp[i][j]=min(dp[i][j],dp[x][j-1]+a[i]);
                dp[y][j]=min(dp[x][j]+a[i],dp[y][j]);
            }
        }
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
