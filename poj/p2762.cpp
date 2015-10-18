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
const int N=1024;
struct Edge
{
    int s,t;
};
int n,m,dfn[N],low[N],in[N],id[N],cnt,dep,mp[N][N];
vector<Edge>edge;
vector<int>g[N];
stack<int>st;

void Addedge(int u,int v)
{
    Edge tp;
    tp.s=u,tp.t=v;
    edge.push_back(tp);
    g[u].push_back(edge.size()-1);
}

void dfs(int u)
{
    int v,i,k,mx=dfn[u]=low[u]=dep++;
    st.push(u);
    for(i=0;i<g[u].size();i++)
    {
        v=edge[g[u][i]].t;
        if(dfn[v]==-1) dfs(v);
        if(mx>low[v]) mx=low[v];
    }
    if(mx<low[u])
    {
        low[u]=mx;
        return ;
    }
    //printf("%d\n",cnt);
    do
    {
        k=st.top();
        st.pop();
        id[k]=cnt;
        low[k]=n;
    }while(k!=u);
    cnt++;
}

int topsort()
{
    int i,u,v,p;
    stack<int>S;
    for(i=0;i<cnt;i++)
    {
        //printf("%d\n",in[i]);
        if(in[i]==0)
            S.push(i);
    }
    //printf("%d\n",S.size());
    p=0;
    while(S.size()==1)
    {
        u=S.top();S.pop();p++;
        for(i=0;i<cnt;i++)
        {
            if(mp[u][i]==1)
            {
                in[i]--;
                if(in[i]==0) S.push(i);
            }
        }
    }
    if(p==cnt) return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            {
                g[i].clear();
                id[i]=i;
            }
        edge.clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            Addedge(u-1,v-1);
        }
        dep=0;
        cnt=0;
        while(!st.empty()) st.pop();
        memset(dfn,0xff,sizeof(dfn));
        for(i=0; i<n; i++)
        {
            if(dfn[i]==-1)
                dfs(i);
        }
        memset(in,0,sizeof(in));
        memset(mp,0,sizeof(mp));
        for(i=0; i<m; i++)
        {
            u=id[edge[i].s];
            v=id[edge[i].t];
            if(u!=v&&!mp[u][v])
            {
                in[v]++;
                mp[u][v]=1;
            }
        }
        if(topsort()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
