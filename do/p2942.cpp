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
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+5;
struct Edge
{
    int u,v;
};

int g[N][N],dfn[N],iscut[N],bccno[N],def,bcc_cnt,odd[N],color[N];
vector<int>G[N],bcc[N];

stack<Edge>S;

bool bipartite(int u,int b)
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(bccno[v]!=b) continue;
        if(color[v]==color[u])
            return 0;
        if(!color[v])
        {
            color[v]=3-color[u];
            if(!bipartite(v,b))
                return 0;
        }
    }
    return 1;
}

int dfs(int u,int fa)
{
    int lowu=dfn[u]=++def;
    int i,child=0;
    for(i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        Edge e;
        e.u=u;
        e.v=v;
        if(!dfn[v])
        {
            S.push(e);
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=dfn[u])
            {
                iscut[u]=1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)
                {
                    Edge x=S.top();
                    S.pop();
                    if(bccno[x.u]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==v) break;
                }
            }
        }
        else if(dfn[v]<dfn[u]&&v!=fa)
        {
            S.push(e);
            lowu=min(lowu,dfn[v]);
        }
    }
    if(fa<0&&child==1) iscut[u]=0;
    return lowu;
}

void find_bcc(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    def=bcc_cnt=0;
    for(int i=0;i<n;i++)
        if(!dfn[i])
            dfs(i,-1);
}
int main()
{
    int n,m,i,j,u,v;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        while(!S.empty()) S.pop();
        for(i=0;i<n;i++)
            G[i].clear();
        memset(g,1,sizeof(g));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            u--;v--;
            g[u][v]=g[v][u]=0;
        }
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(g[i][j])
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
        find_bcc(n);

        memset(odd,0,sizeof(odd));
        for(i=1;i<=bcc_cnt;i++)
        {
            memset(color,0,sizeof(color));
            for(j=0;j<bcc[i].size();j++)
                bccno[bcc[i][j]]=i;
            u=bcc[i][0];
            color[u]=1;
            if(!bipartite(u,i))
                for(j=0;j<bcc[i].size();j++)
                    odd[bcc[i][j]]=1;
        }

        int ans=n;
        for(i=0;i<n;i++) if(odd[i]) ans--;
        printf("%d\n",ans);
    }
    return 0;
}
