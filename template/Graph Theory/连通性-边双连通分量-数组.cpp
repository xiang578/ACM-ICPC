//poj 3177
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
const int MAXN=100000+5;
const int MAXM=400000+10;

struct Edge
{
    int to,next,cut;
} edge[MAXM];

int head[MAXN],tot,low[MAXN],dfn[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组是连通块的序号
int index,top;
int block;
int instack[MAXN];
int bridge;

void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=0;
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
            if(low[v]>low[u])
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
int du[MAXN];
void solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    index=top=block=0;
    Tarjan(1,0);
    int ans=0;
    memset(du,0,sizeof(du));
    for(int i=1; i<=n; i++)
        for(int j=head[i]; j!=-1; j=edge[j].next)
            if(edge[j].cut)
                du[Belong[i]]++;
    for(int i=1; i<=block; i++)
        if(du[i]==1)
            ans++;
    printf("%d\n",(ans+1)/2);
}

int main()
{
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)==2)
    {
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        solve(n);
    }
    return 0;
}
