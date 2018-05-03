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
typedef vector<int> VI;
typedef double db;
const int N=100000+10;
const int inf=0x7fffffff;
struct node
{
    int to,next;
}g[2*N];
int cnt,fa[N],dep[N],sz[N],son[N],w[N],top[N],tot,head[N],mp[N][3];

void add_Node(int x,int y)
{
    g[cnt].to=y;
    g[cnt].next=head[x];
    head[x]=cnt++;
}


void dfs1(int x,int f)
{
    int y,mx=-1;
     fa[x]=f;
     sz[x]=1;
     dep[x]=dep[f]+1;
     for(int i=head[x];i!=-1;i=g[i].next)
     {
         y=g[i].to;
         if(y==f) continue;
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
    for(int i=head[x];i!=-1;i=g[i].next)
    {
        y=g[i].to;
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

void update(int o,int l,int r,__int64 val)
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
        tree[o].mx=tree[o*2].mx+tree[o*2+1].mx;
    }
}

__int64 query(int o,int l,int r)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        return tree[o].mx;
    }
    else
    {
        __int64 ans=0;
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid) ans+=query(o*2,l,r);
        if(r>mid) ans+=query(o*2+1,l,r);
        return ans;
    }
}

__int64 Find(int x,int y)
{
    int f1=top[x],f2=top[y];
    __int64 tmp=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(x,y);
        }
        tmp+=query(1,w[f1],w[x]);
        x=fa[f1];
        f1=top[x];
    }
    if(x==y) return tmp;
    if(dep[x]>dep[y]) swap(x,y);
    return tmp+query(1,w[son[x]],w[y]);
}

int main()
{
    int _,n,a,b,c,m,s;
    __int64 t;
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        cnt=0;
        memset(head,0xff,sizeof(head));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%I64d",&a,&b,&t);
            mp[i][0]=a;
            mp[i][1]=b;
            mp[i][2]=t;
            add_Node(a,b);
            add_Node(b,a);
        }
        memset(son,0,sizeof(son));
        tot=1;
        dep[0]=0;
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,tot-1);
        for(int i=0;i<n-1;i++)
        {
            a=mp[i][0];b=mp[i][1];
            if(dep[a]>dep[b])
                 swap(mp[i][1],mp[i][0]);
            update(1,w[mp[i][1]],w[mp[i][1]],mp[i][2]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d%I64d",&a,&t);
                update(1,w[mp[a-1][1]],w[mp[a-1][1]],t);
            }
            else
            {
                scanf("%d",&b);
                printf("%I64d\n",Find(s,b));
                s=b;
            }
        }
    }
    return 0;
}
