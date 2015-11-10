//uva 315
//割点条件根节点有两个或两个以上节点
//或者其他节点u有一个子女w，low[w]>=dfn[u];
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+5;

struct Edge
{
    int from,to;
};

vector<Edge>edges;
vector<int>G[MAXN*MAXN];
int low[MAXN],dfn[MAXN],vis[MAXN],dep,ans,sub[MAXN];

void addedge(int from,int to)
{
    Edge tp;
    tp.from=from;
    tp.to=to;
    edges.push_back(tp);
    G[from].push_back(edges.size()-1);
}

void dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=edges[G[u][i]].to;
        if(!vis[v])
        {
            vis[v]=1;
            dep++;
            dfn[v]=low[v]=dep;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                sub[u]++;
            }
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}
int main()
{
    int _,i,j,u,v,c,n;
    char st;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        ans=0;
        edges.clear();
        for(i=0; i<MAXN; i++)
            G[i].clear();
        while(~scanf("%d",&u))
        {
            if(u==0) break;
            while(1)
            {
                st=getchar();
                if(st==10) break;
                scanf("%d",&v);
                addedge(u,v);
                addedge(v,u);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(sub,0,sizeof(sub));
        dep=0;
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dep++;
                dfn[i]=low[i]=dep;
                dfs(i);
                if(sub[i]>=1)sub[i]-=1;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(sub[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
