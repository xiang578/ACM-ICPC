#include<bits/stdc++.h>
using namespace std;
int dp[1024],vis[1024],m;
const int inf=1000001;
struct node
{
    int to,w;
}p;

vector<node>v[1024];

void dfs(int x,int up)
{
    int i,tmp=0,f=0;
    node p;
    vis[x]=1;
    for(i=0; i<v[x].size(); i++)
    {
        p=v[x][i];
        if(vis[p.to]==1) continue;
        dfs(p.to,up);
        f=1;
        if(p.w>up)
            tmp+=dp[p.to];
        else
            tmp+=min(dp[p.to],p.w);
    }
    if(f)
        dp[x]=tmp;
    else
        dp[x]=inf;
}

int main()
{
    int i,n,a,b,w,l,r,ans,len,up;
    node p;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0; i<=n; i++)
            v[i].clear();
        len=0;
        for(i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            p.w=w;
            p.to=b;
            v[a].push_back(p);

            p.to=a;
            v[b].push_back(p);
            len=max(w,len);
        }
        l=1;
        r=len;
        ans=inf;
        while(l<=r)
        {
            up=(l+r)/2;
            memset(vis,0,sizeof(vis));
            memset(dp,0,sizeof(dp));
            dfs(1,up);
            //printf("%d\n",dp[1]);
            if(dp[1]<=m)
            {
                r=up-1;
                ans=min(ans,up);
            }
            else
            {
                l=up+1;
            }
        }
        if(ans>=inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
