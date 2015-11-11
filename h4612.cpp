#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=200000+5;
int dfn[N],def,p[N],cnt,low[N],inq[N],vis[N],dist[N];
struct Edge
{
    int to,tag;
};
vector<Edge>edges;
vector<int>G[N*5];

void AddEdge(int from,int to)
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
        tp.to=to;tp.tag=0;
        edges.push_back(tp);
        G[from].push_back(edges.size()-1);
    }
}

int Find(int x)
{
    if(x==p[x]) return x;
    else return p[x]=Find(p[x]);
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy) p[fx]=fy;
}

void dfs(int u,int fa)
{
    vis[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=edges[G[u][i]].to;
        if(v!=fa&&vis[v]==1)
            low[u]=min(low[u],dfn[v]);
        if(!vis[v])
        {
            low[v]=dfn[v]=++def;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]<=dfn[u]||edges[G[u][i]].tag) Union(v,u);
            else cnt++;
        }
    }
    vis[u]=2;
}

void find_bcc(int n)
{
    int i;
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    def=cnt=0;
    for(i=1; i<=n; i++)
        if(!vis[i])
        {
            vis[i]=1;
            dfn[i]=low[i]=++def;
            dfs(i,-1);
        }
}

int bfs(int u,int f)
{
    int st,i,v,tn,mt=0,ed=u;
    queue<int>q;
    queue<int>t;
    q.push(u);
    t.push(0);
    memset(inq,0xff,sizeof(inq));
    inq[u]=0;
    while(!q.empty())
    {
        u=q.front();
        tn=t.front();
        q.pop();
        t.pop();
        for(i=0;i<G[u].size();i++)
        {
            v=edges[G[u][i]].to;
            v=Find(v);
            if(v==u||inq[v]!=-1) continue;
            inq[v]=1;
            if(tn+1>mt)
            {
                mt=tn+1;
                ed=v;
            }
            if(inq[v]<tn+1)
            {
                inq[v]=tn+1;
            q.push(v);
            t.push(tn+1);
            }
        }
    }
    if(f==1) return mt;
    else return ed;
}

/*int bfs(int u,int f)
{
    queue<int>q;
    int v,i,st,mx;
    while(!q.empty()) q.pop();
    memset(inq,0,sizeof(inq));
    q.push(u);
    dist[u]=0;
    inq[u]=1;
    mx=0;
    while(!q.empty())
    {
        
    }
}*/

int main()
{
    int i,j,n,m,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        edges.clear();
        for(i=0; i<=n; i++)
        {
            G[i].clear();
            p[i]=i;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
            AddEdge(v,u);
        }
        find_bcc(n);
        //printf("%d\n",cnt);
        printf("%d\n",cnt-bfs(bfs(Find(1),0),1));
    }
    return 0;
}
