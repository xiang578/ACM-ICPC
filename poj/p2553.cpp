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
const int N=5000+5;

struct Edge
{
    int s,t;
};
vector<Edge>edge;
vector<int>g[N],gt[N];
int n,m,vis[N],in[N],ord[N],id[N],cnt;

void Addedge(int s,int t)
{
    Edge tp;
    tp.s=s;tp.t=t;
    edge.push_back(tp);
    g[s].push_back(edge.size()-1);
    gt[t].push_back(edge.size()-1);
}

void dfs(int u)
{
    int i,v;
    vis[u]=1;
    for(i=0;i<g[u].size();i++)
    {
        v=edge[g[u][i]].t;
        if(!vis[v]) dfs(v);
    }
    ord[cnt++]=u;
}

void dfst(int u)
{
    int i,v;
    vis[u]=1;
    id[u]=cnt;
    for(i=0;i<gt[u].size();i++)
    {
        v=edge[gt[u][i]].s;
        if(!vis[v]) dfst(v);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,u,v;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        edge.clear();
        for(i=0;i<n;i++)
        {
            g[i].clear();
            gt[i].clear();
            id[i]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            Addedge(u-1,v-1);
        }
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            if(!vis[i]) dfs(i);
        }
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=n-1;i>=0;i--)
        {
            if(!vis[ord[i]])
            {
                dfst(ord[i]);
                cnt++;
            }
        }
        memset(in,0,sizeof(in));
        for(i=0;i<m;i++)
        {
            u=id[edge[i].s];
            v=id[edge[i].t];
            if(u!=v) in[u]++;
        }
        int sf=0;
        for(i=0;i<n;i++)
        {
            //printf("%d\n",id[i]);
            if(in[id[i]]==0)
            {
                if(sf==0) sf++;
                else printf(" ");
                printf("%d",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
