#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const long long inf=0x3fffffffffffffff;
struct node
{
    int u,v;
    long long d,c;
} G[N];
vector<int>g[N];
int n,m,inq[N];

long long d[N],c[N];

void xiang()
{
    int i,u,v;
    for(i=0;i<n;i++)
    {
        c[i]=inf;
        inq[i]=0;
        d[i]=inf;
    }
    queue<int>Q;
    inq[0]=1;
    d[0]=0;
    c[0]=0;
    Q.push(0);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        inq[u]--;
        //printf("%d\n",u);
        for(i=0;i<g[u].size();i++)
        {
            if(G[g[u][i]].u==u) v=G[g[u][i]].v;
            else v=G[g[u][i]].u;
            if(d[v]>=d[u]+G[g[u][i]].d)
            {
                if(d[v]==d[u]+G[g[u][i]].d)
                    c[v]=min(c[v],G[g[u][i]].c);
                else
                    c[v]=G[g[u][i]].c;
                d[v]=d[u]+G[g[u][i]].d;
                if(inq[v]==0)
                {
                    inq[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
int main()
{
    int i,j,u,v,t;
    long long time,cost;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            g[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%lld%lld",&G[i].u,&G[i].v,&G[i].d,&G[i].c);
            g[G[i].u].push_back(i);
            g[G[i].v].push_back(i);
        }
        xiang();
        time=cost=0;
        for(i=0; i<n;i++)
        {
            time+=d[i];
            cost+=c[i];
        }
        printf("%lld %lld\n",time,cost);
    }
    return 0;
}
