#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0xfffffff;
const int M=1000000+5;
struct Edge
{
    int u,v,w;
} edge[M];

int n,m,dis[1024],flag[1024],cnt[1024],now[1024],len,vis[1024];
vector<int>g[1024];

void spfa()
{
    queue<int>q;
    int i,u,v,k;
    memset(flag,0,sizeof(flag));
    for(i=1; i<=n; i++)
        dis[i]=inf;
    dis[2]=0;
    q.push(2);
    while(!q.empty())
    {
        u=q.front();
        //printf("%d\n",u);
        q.pop();
        flag[u]=0;
        for(i=0; i<g[u].size(); i++)
        {
            k=g[u][i];
            if(edge[k].u==u)
            {
                v=edge[k].v;
                if(dis[u]+edge[k].w<=dis[v])
                {
                    dis[v]=dis[u]+edge[k].w;
                    if(flag[v]==0)
                    {
                        flag[v]=1;
                        q.push(v);
                    }
                }
            }
            else if(edge[k].v==u)
            {
                v=edge[k].u;
                if(dis[u]+edge[k].w<=dis[v])
                {
                    dis[v]=dis[u]+edge[k].w;
                    if(flag[v]==0)
                    {
                        flag[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

int dfs(int u)
{
    if(u==2)
    {
        vis[u]=1;
        return cnt[u]=1;
    }
    vis[u]=1;
    int i,v,k;
    for(i=0; i<g[u].size(); i++)
    {
        k=g[u][i];
        if(edge[k].u==u) v=edge[k].v;
        else v=edge[k].u;
        if(dis[u]>dis[v])
        {
            now[v]=now[u]+edge[k].w;
            if(vis[v]==0) cnt[u]+=dfs(v);
           else cnt[u]+=cnt[v];
        }
    }
    return cnt[u];
}

int main()
{
    int i,j,u,v,w;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        scanf("%d",&m);
        for(i=1; i<=n; i++)
            g[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[i].u=u;
            edge[i].v=v;
            edge[i].w=w;
            g[u].push_back(i);
            g[v].push_back(i);
        }
        spfa();
        len=dis[1];
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(i=0; i<=n; i++)
            now[i]=inf;
        now[1]=0;
        dfs(1);
        printf("%d\n",cnt[1]);
    }
    return 0;
}
