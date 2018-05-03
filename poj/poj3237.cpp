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
const int inf=0x7fffffff;
const int N=10000+10;

struct edge
{
    int a,b,w;
}g[2*N];
vector<int>v[N];
int fa[N],dep[N],sz[N],son[N],w[N],tot,top[N];

struct Tree
{
    int l,r,f,mx,mi;
}tree[4*N];

void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].f=-1;
    tree[o].mx=-inf;
    tree[o].mi=inf;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
    }
}

void pushdown(int o)
{
    if(tree[o].f!=-1)
    {
        tree[o*2].f=tree[o*2+1].f=tree[o].f;
        swap(tree[o*2].mx,tree[o*2].mi);
        tree[o*2].mx=-tree[o*2].mx;
        tree[o*2].mi=-tree[o*2].mi;

        swap(tree[o*2+1].mx,tree[o*2+1].mi);
        tree[o*2+1].mx=-tree[o*2+1].mx;
        tree[o*2+1].mi=-tree[o*2+1].mi;
        tree[o].f=-1;
    }
}

void update(int o,int l,int r,int val)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
        tree[o].f=-1;
        tree[o].mx=tree[o].mi=val;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update(o*2,l,r,val);
        if(r>mid) update(o*2+1,l,r,val);
        tree[o].mx=max(tree[o*2].mx,tree[o*2+1].mx);
        tree[o].mi=min(tree[o*2].mi,tree[o*2+1].mi);
    }
}

void update2(int o,int l,int r)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
        tree[o].mx=-tree[o].mx;
        tree[o].mi=-tree[o].mi;
        swap(tree[o].mx,tree[o].mi);
        tree[o].f=0;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update2(o*2,l,r);
        if(r>mid) update2(o*2+1,l,r);
        tree[o].mx=max(tree[o*2].mx,tree[o*2+1].mx);
        tree[o].mi=min(tree[o*2].mi,tree[o*2+1].mi);
    }
}

int query(int o,int l,int r)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
       return tree[o].mx;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(r<=mid) return query(o*2,l,r);
        else if(l>mid) return query(o*2+1,l,r);
        else return max(query(o*2+1,l,r),query(o*2,l,r));
    }
}

void dfs1(int x,int f)
{
    fa[x]=f;
    dep[x]=dep[f]+1;
    sz[x]=1;
    int m=0,y;
    for(int i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(y==f) continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(m==0||sz[y]>sz[m])
        {
            son[x]=y;
            m=y;
        }
    }
}

void dfs2(int x,int tp)
{
    top[x]=tp;
    if(son[x]!=0)
    {
        w[x]=++tot;
        dfs2(son[x],tp);
    }
    else
    {
        w[x]=++tot;
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

int Find(int x,int y)
{
    int f1=top[x],f2=top[y];
    int tmp=-inf;
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

void change(int x,int y)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(x,y);
        }
        update2(1,w[f1],w[x]);
        x=fa[f1];
        f1=top[x];
    }

    if(x==y) return ;
    if(dep[x]>dep[y]) swap(x,y);
    update2(1,w[son[x]],w[y]);
}

int main()
{
    int _,a,b,n,c;
    char s[1024];
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        tot=0;
        for(int i=0;i<=n;i++)
            v[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[i].a=a;
            g[i].b=b;
            g[i].w=c;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dep[0]=0;
        memset(son,0,sizeof(son));
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,tot);
        //printf("\n");
        for(int i=0;i<n-1;i++)
        {
            if(dep[g[i].a]>dep[g[i].b])
                swap(g[i].a,g[i].b);
            update(1,w[g[i].b],w[g[i].b],g[i].w);
        }
        while(~scanf("%s",s))
        {
            if(s[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",Find(a,b));
            }
            else if(s[0]=='C')
            {
                scanf("%d%d",&a,&b);
                update(1,w[g[a-1].b],w[g[a-1].b],b);
            }
            else if(s[0]=='N')
            {
                scanf("%d%d",&a,&b);
                change(a,b);
            }
            else
                break;
        }
    }
    return 0;
}
