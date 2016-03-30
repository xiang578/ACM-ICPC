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
using namespace std;
const int MAXN=4e5+100;
const int MAXM=2*MAXN;

struct Edge
{
    int to,next,cut,val;
} edge[MAXM];

int head[MAXN],tot,low[MAXN],dfn[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组是连通块的序号
int index,top,st,ed;
int block;
int instack[MAXN],has[MAXN],vis[MAXN];
int bridge;
vector<Edge>G[MAXN];
queue<int>q;
void addedge(int u,int v,int val)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=0;
    edge[tot].val=val;
    head[u]=tot++;
}

void Tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre) continue;
        if(!dfn[v])
        {
            Tarjan(v,u);
            if(low[u]>low[v]) low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=1;
                edge[i^1].cut=1;
            }
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        block++;
        do
        {
            v=Stack[--top];
            instack[v]=0;
            Belong[v]=block;
        }
        while(v!=u);
    }
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

int solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(Belong,0,sizeof(Belong));
    index=top=block=0;
    Tarjan(1,0);
     for(int i=1;i<=n;i++)
    {
        if(Belong[i]==0)
        {
            block++;
            Belong[i]=block;
        }
    }
    for(int i=1; i<=block; i++)
    {
        has[i]=0;
        G[i].clear();
    }
    int u,v,now;
    Edge e;

    for(int i=1; i<=n; i++)
    {
        for(int j=head[i]; j!=-1; j=edge[j].next)
        {
            if(edge[j].cut)
            {
                u=Belong[i];
                v=Belong[edge[j].to];
                e.to=v;
                e.val=edge[j].val;
                G[u].push_back(e);
            }
            else if(edge[j].val==1)
                has[Belong[i]]=1;
        }
    }
    u=Belong[st];
    v=Belong[ed];
    memset(vis,0,sizeof(vis));
    if(u==v) return has[v];
    else
    {
        q.push(u);
        vis[u]=1;
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(int i=0;i<G[u].size();i++)
            {
                 now=G[u][i].to;
                 if(vis[now]) continue;
                 else vis[now]=1;
                 if(has[u]==1||has[now]==1||G[u][i].val==1) has[now]=1;
                 else has[now]=0;
                if(now==v) return has[now];
                q.push(now);
            }
        }
        return 0;
    }
}

int main()
{
    int n,m;
    int u,v,w,k;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(k=1; k<=m; k++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        scanf("%d%d",&st,&ed);
        if(solve(n)==1) puts("YES");
        else puts("NO");
    }
    return 0;
}
