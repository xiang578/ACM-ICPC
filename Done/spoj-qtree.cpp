
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define cl(a) memset(a,0,sizeof(a))
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const ll mod=1000000007;
const int N=10000+10;
const int inf=0x7fffffff;
struct edge
{
    int a,b,w;
}g[2*N];
vector<int>v[N];
int fa[N],dep[N],sz[N],son[N],w[N],vis[N],top[N],tot;

void dfs1(int x,int f)
{
    int y,mx=-1;
     vis[x]=1;
     fa[x]=f;
     sz[x]=1;
     dep[x]=dep[f]+1;
     for(int i=0;i<v[x].size();i++)
     {
         y=v[x][i];
         if(vis[y]==1) continue;
         dfs1(y,x);
         sz[x]+=sz[y];
         if(sz[y]>mx){mx=sz[y];son[x]=y;}
     }
}

void dfs2(int x,int tp)
{
    top[x]=tp;
    if(son[x]!=0)
    {
        w[x]=tot++;
        dfs2(son[x],tp);
    }
    else
    {
        w[x]=tot++;
        return ;
    }
    int y;
    for(int i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(y!=son[x]&&y!=fa[x])
            dfs2(y,y);
    }
}

struct Tree
{
    int l,r,mx;
}tree[4*N];
void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].mx=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
    }
}

void update(int o,int l,int r,int val)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        tree[o].mx=val;
    }
    else
    {
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update(o*2,l,r,val);
        if(r>mid) update(o*2+1,l,r,val);
        tree[o].mx=(tree[o*2].mx,tree[o*2+1].mx);
    }
}

int query(int o,int l,int r)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        return tree[o].mx;
    }
    else
    {
        int ans=0;
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid) ans=max(ans,query(o*2,l,r));
        if(r>mid) ans=max(ans,query(o*2+1,l,r));
        return ans;
    }
}

int Find(int x,int y)
{
    int f1=top[x],f2=top[y];
    int tmp=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(x,y);
        }
        tmp=max(tmp,query(1,w[f1],w[x]));
        x=fa[f1];
        f1=top[x];
    }
    if(x==y) return tmp;
    if(dep[x]>dep[y]) swap(x,y);
    return max(tmp,query(1,w[son[x]],w[y]));
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,a,b,c;
    char s[100];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[i].a=a;g[i].b=b;
            g[i].w=c;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        memset(son,0,sizeof(son));
        tot=1;
        dep[0]=0;
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,tot-1);
        for(int i=0;i<n-1;i++)
        {
            a=g[i].a;b=g[i].b;
            if(dep[a]>dep[b])
                 swap(g[i].a,g[i].b);
            update(1,w[g[i].b],w[g[i].b],g[i].w);
        }
        while(~scanf("%s",s))
        {
            if(s[0]=='D') break;
            scanf("%d%d",&a,&b);
            if(s[0]=='C')
                update(1,w[g[a-1].b],w[g[a-1].b],b);
            else
                printf("%d\n",Find(a,b));
        }
    }
    return 0;
}
