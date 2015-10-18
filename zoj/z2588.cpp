#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int from,to,tag,id;
};

int n,m,dfn[100000+5],low[100000+5],vis[100000+5],dep,b[100000+5],num=0;
vector<Edge>edges;
vector<int>G[100000+5];
void AddEdge(int from,int to,int id)
{
    int i,flag=0;
    for(i=0;i<G[from].size();i++)
        if(edges[G[from][i]].to==to)
        {
            edges[G[from][i]].tag++;flag=1;break;
        }
    if(!flag)
    {
        Edge tp;
        tp.from=from;tp.to=to;tp.tag=0;tp.id=id;
        edges.push_back(tp);
        G[from].push_back(edges.size()-1);
    }
}

void dfs(int u,int fa)
{
    dfn[u]=low[u]=++dep;
    for(int i=0;i<G[u].size();i++)
    {
        Edge t=edges[G[u][i]];
        if(!vis[t.to])
        {
            vis[t.to]=1;
            dfs(t.to,u);
            low[u]=min(low[u],low[t.to]);
            if(low[t.to]>dfn[u]&&!t.tag)
            {
                b[num]=t.id;
                num++;
            }
        }
        else if(t.to!=fa) low[u]=min(low[u],dfn[t.to]);
    }
}

int main()
{
    int _,i,u,v,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        edges.clear();
        for(i=0;i<=n;i++)
            G[i].clear();
        for(i=1;i<=m;i++)
        {
          scanf("%d%d",&u,&v);
            AddEdge(u,v,i);
            AddEdge(v,u,i);
        }
        memset(vis,0,sizeof(vis));
        memset(b,0,sizeof(b));
        num=0;
        vis[1]=1;
        dep=0;
        dfs(1,-1);
        printf("%d\n",num);
        sort(b,b+num);
        for(i=0;i<num;i++)
        {
            if(i) printf(" ");
            printf("%d",b[i]);
        }
        if(num) printf("\n");
        if(_) printf("\n");
    }
    return 0;
}
