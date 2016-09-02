/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e5+10;
int n,m,use[N],u,v,tot,in[N],cnt[N];
struct node
{
    int u,v,w;
}e[N];
vector<int>g[N];

void add(int u,int v)
{
    node t;
    t.u=u;
    t.v=v;
    t.w=0;
    e[tot]=t;
    g[u].push_back(tot);
    g[v].push_back(tot);
    tot++;
}

void dfs(int x,int st)
{
    for(int i=0;i<g[x].size();i++)
    {
        int y;
        int t=g[x][i];
        if(e[t].w==1) continue;
        if(e[t].u==x) y=e[t].v;
        else y=e[t].u;
        e[t].w=1;
        if(use[y]==1||in[y]==1) in[st]=1;
        if(in[y]==0) in[y]=1;
        if(use[y]==0) {use[y]==1;dfs(y,st);}
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    memset(use,0,sizeof(use));
    memset(in,0,sizeof(in));
    memset(cnt,0,sizeof(cnt));
    tot=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        cnt[u]++;
        cnt[v]++;
        add(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(use[i]==0)
            dfs(i,i);
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
