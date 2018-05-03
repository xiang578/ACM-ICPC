#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=40000+100;
struct node
{
    int to,w;
}t;
int tot,n,m,vs[N*2+10],dep[N*2+10],id[N],dis[N],d[N*2+10][50];
vector<node>g[N];

void dfs(int v,int p,int de)
{
    id[v]=tot;
    vs[tot]=v;
    dep[tot++]=de;
    for(int i=0;i<g[v].size();i++)
    {
        if(g[v][i].to!=p)
        {
            dis[g[v][i].to]=dis[v]+g[v][i].w;
            dfs(g[v][i].to,v,de+1);
            vs[tot]=v;
            dep[tot++]=de;
        }
    }
}

void rmq_init(int n)
{
    memset(d,0xff,sizeof(d));
    for(int i=0;i<n;i++) d[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            int u=d[i][j-1];
            int v=d[i+(1<<(j-1))][j-1];
            if(dep[u]<dep[v]) d[i][j]=u;
            else d[i][j]=v;
        }
}

int query(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    int u=d[l][k];
    int v=d[r-(1<<k)+1][k];
    if(dep[u]<dep[v]) return u;
    else return v;
}

int lca(int u,int v)
{
    if(id[u]>id[v]) swap(u,v);
    return vs[query(id[u],id[v]+1)];
}

int main()
{
    int _,a,b,w;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            g[i].clear();
            tot=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            t.to=b;
            t.w=w;
            g[a].push_back(t);
            t.to=a;
            t.w=w;
            g[b].push_back(t);
        }
        dis[1]=0;
        dfs(1,-1,0);
        rmq_init(2*n-1);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            int ans=dis[a]+dis[b]-2*dis[lca(a,b)];
            printf("%d\n",ans);
        }
    }
    return 0;
}
