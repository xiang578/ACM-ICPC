#include<bits/stdc++.h>
int n,m,dp[10000];
int p[1024],q[1024],v[1024];
struct node
{
    int x,id;
}t[1024];

int cmp(node n1,node n2)
{
    return n1.x<n2.x;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&q[i],&p[i],&v[i]);
            t[i].id=i;
            t[i].x=p[i]-q[i];
        }
        std::sort(t,t+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int k=t[i].id;
            for(int j=m;j>=p[k];j--)
            {
                dp[j]=std::max(dp[j],dp[j-q[k]]+v[k]);
            }
        }
        int ans=0;
        for(int i=0;i<=m;i++)
            ans=std::max(ans,dp[i]);
        printf("%d\n",ans);
    }
}
