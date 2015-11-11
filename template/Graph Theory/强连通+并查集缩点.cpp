//3177
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

int dfn[5000+5],def,p[5000+5],cnt,bridge[20005][2],in[5000+5],low[5000+5];
vector<int>G[5000+5];

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
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!dfn[v])
        {
            low[v]=dfn[v]=++def;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]<=dfn[u])
            {
                Union(v,u);
            }
            else
            {
                bridge[cnt][0]=u;
                bridge[cnt][1]=v;
                //cout<<u<<v<<endl;
                cnt++;
            }
        }
        else if(dfn[u]>dfn[v]&&v!=fa)
        low[u]=min(low[u],dfn[v]);
    }
}

void find_bcc(int n)
{
    int i;
    memset(dfn,0,sizeof(dfn));
    def=cnt=0;
    for(i=0; i<n; i++)
        if(!dfn[i])
        {
            dfn[i]=low[i]=++def;
            dfs(i,-1);
        }
}
int main()
{
    int i,j,n,m,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<n; i++)
        {
            G[i].clear();
            p[i]=i;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        find_bcc(n);
        memset(in,0,sizeof(in));
        for(i=0;i<cnt;i++)
        {
            u=bridge[i][0];
            v=bridge[i][1];
            in[Find(u)]++;
            in[Find(v)]++;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            //printf("%d %d\n",i,Find(i));
            if(in[i]==1)
                ans++;
        }
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}
