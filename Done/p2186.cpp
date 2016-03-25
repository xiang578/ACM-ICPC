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
const int N=100000+5;
struct Edge
{
    int s,t;
};
vector<Edge>edge;
stack<int>st;
vector<int>g[100000+5];
int n,m,in[N],id[N],dfn[N],low[N],def,cnt;

void Addedge(int u,int v)
{
    Edge tp;
    tp.s=u,tp.t=v;
    edge.push_back(tp);
    g[u].push_back(edge.size()-1);
}

void dfs(int u)
{
    int k,mx=dfn[u]=low[u]=++def;
    st.push(u);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=edge[g[u][i]].t;
        if(dfn[v]==-1) dfs(v);
        if(low[v]<mx) mx=low[v];
    }
    if(mx<low[u])
    {
        low[u]=mx;
        return ;
    }
    do
    {
        k=st.top();
        id[k]=cnt;
        low[k]=n;
        st.pop();
    }
    while(k!=u);
    cnt++;
}
int main()
{
    int i,j,u,v,ans,pos;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<n; i++)
        {
            g[i].clear();
            id[i]=i;
            in[i]=0;
        }
        edge.clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            Addedge(u-1,v-1);
        }
        while(!st.empty()) st.pop();
        def=0;
        cnt=0;
        memset(dfn,0xff,sizeof(dfn));
        for(i=0; i<n; i++)
        {
            if(dfn[i]==-1)
                dfs(i);
        }
        for(i=0; i<m; i++)
        {
            u=id[edge[i].s];
            v=id[edge[i].t];
            if(u!=v) in[u]++;
            //printf("%d %d\n",u,v);
        }
        ans=0;
        pos=-1;
        for(i=0; i<cnt; i++)
        {
            if(in[i]==0)
            {
                //printf("%d\n",id[i]);
                if(pos==-1)
                {
                    ans++;
                    pos=i;
                }
                else if(pos!=i) ans++;
            }
        }
        // printf("%d\n",pos);
        if(ans!=1) printf("0\n");
        else
        {
            ans=0;
            for(i=0; i<n; i++)
            {
                if(id[i]==pos)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
