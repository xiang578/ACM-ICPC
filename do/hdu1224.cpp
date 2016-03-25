#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int dp[120],a[120],d[120];
vector<int>v;
vector<int>g[120];

int main()
{
    int _,k,n,i,j,m,p,q,t,u;
    scanf("%d",&_);
    for(k=1; k<=_; k++)
    {
        v.clear();
        scanf("%d",&n);
        for(i=1; i<=n+1; i++)
        {
            g[i].clear();
            dp[i]=inf;
        }
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        a[n+1]=0;
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&p,&q);
            g[p].push_back(q);
        }
        dp[1]=a[1];
        for(i=1; i<=n; i++)
        {
            if(dp[i]==inf) continue;
            for(j=0; j<g[i].size(); j++)
            {
                u=g[i][j];
                t=dp[i]+a[u];
                if(dp[u]==inf||dp[u]<t)
                {
                    dp[u]=t;
                    d[u]=i;
                }
            }
        }
        t=n+1;
        while(t!=1)
        {
            t=d[t];
            v.push_back(t);
        }
        printf("CASE %d#\n",k);
        printf("points : %d\n",dp[n+1]);
        printf("circuit : ");
        for(i=v.size()-1; i>=0; i--)
            printf("%d->",v[i]);
        printf("1\n");
        if(k!=_) printf("\n");
    }
    return 0;
}
