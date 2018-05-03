#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<17;
const ll inf=1e18;
ll a[20],dp[N][20];
int n,t,f[20],b[20];

int get(int x)
{
    int ret=0;
    while(x>0)
    {
        if(x%2==1) ret++;
        x/=2;
    }
    return ret;
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int __=1; __<=_; __++)
    {
        scanf("%d",&n);
        memset(f,0xff,sizeof(f));
        for(int i=0; i<n; i++)
        {
            scanf("%lld%d",&a[i],&b[i]);
            //printf("%d\n",b[i]);
            if(b[i]!=-1) f[b[i]]=i;
        }
        int up=1<<n;
        for(int i=0; i<up; i++)
            for(int j=0; j<n; j++)
                dp[i][j]=-inf;
        if(f[0]!=-1)
        {
            dp[1<<f[0]][f[0]]=0;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int e=1<<i;
                if(b[i]!=-1) continue;
                dp[e][i]=0;
            }
        }
        for(int i=1; i<up; i++)
        {
            int k=get(i);
            for(int o=0; o<n; o++)
            {
                if(dp[i][o]==-inf) continue;
                if(f[k]!=-1)
                {
                    dp[i+(1<<f[k])][f[k]]=max(dp[i+(1<<f[k])][f[k]],dp[i][o]+a[o]*a[f[k]]);
                }
                else
                {
                    for(int j=0; j<n; j++)
                    {
                        int e=1<<j;
                        if(e&i) continue;
                        if(b[j]!=-1||j==o) continue;
                        e=i+e;
                        dp[e][j]=max(dp[e][j],dp[i][o]+a[o]*a[j]);
                    }
                }
            }
        }
        ll ans=-inf;
        for(int i=0; i<n; i++)
            ans=max(ans,dp[up-1][i]);
        printf("Case #%d:\n%lld\n",__,ans);
    }
    return 0;
}
