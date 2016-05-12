#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200000+10;
typedef long long ll;
struct
{
    int l,r;
    ll f,sum;
} tree[4*N];

int g[N][2],top[N],fa[N],dep[N],son[N],sz[N],w[N],tot,out[N];
vector<int>v[N];
ll c[N];

void dfs1(int x,int f)
{
    int y,m=0;
    dep[x]=dep[f]+1;
    fa[x]=f;
    sz[x]=1;
    for(int i=0; i<v[x].size(); i++)
    {
        y=v[x][i];
        if(y==f) continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(m==0||sz[y]>sz[m])
        {
            m=y;
            son[x]=y;
        }
    }
}
void dfs2(int x,int tp)
{
    top[x]=tp;
    out[x]=w[x]=++tot;
    if(son[x]==0) {return ;}
    dfs2(son[x],tp);
    out[x]=max(out[x],out[son[x]]);
    for(int i=0; i<v[x].size(); i++)
    {
        int y=v[x][i];
        if(y==fa[x]||y==son[x]) continue;
        dfs2(y,y);
        out[x]=max(out[x],out[y]);
    }
}
void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].f=0;
    tree[o].sum=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
    }
}

void pushdown(int o)
{
    if(tree[o].l==tree[o].r)  return ;
    if(tree[o].f!=0)
    {
        tree[o*2].f+=tree[o].f;
        tree[o*2+1].f+=tree[o].f;
        tree[o*2].sum=tree[o*2].sum+(tree[o*2].r-tree[o*2].l+1)*tree[o].f;
        tree[o*2+1].sum=tree[o*2+1].sum+(tree[o*2+1].r-tree[o*2+1].l+1)*tree[o].f;
        tree[o].f=0;
    }
}

void update(int o,int k,ll val)
{
    if(k==tree[o].l&&tree[o].r==k)
    {
        tree[o].sum=val;
        tree[o].f=0;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(k<=mid)  update(o*2,k,val);
        else update(o*2+1,k,val);
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

void update2(int o,int l,int r,ll val)
{
    if(l==tree[o].l&&tree[o].r==r)
    {

        tree[o].f+=val;
        tree[o].sum=tree[o].sum+(tree[o].r-tree[o].l+1)*val;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(r<=mid)  update2(o*2,l,r,val);
        else if(l>mid) update2(o*2+1,l,r,val);
        else
        {
            update2(o*2,l,mid,val);
            update2(o*2+1,mid+1,r,val);
        }
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

ll query(int o,int l,int r)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
        return tree[o].sum;
    }
    else
    {
        pushdown(o);
        int ret=0;
        int mid=(tree[o].l+tree[o].r)/2;
        if(r<=mid)  query(o*2,l,r);
        else  if(l>mid) query(o*2+1,l,r);
        else return query(o*2,l,mid)+query(o*2+1,mid+1,r);
    }
}

ll Find(int x,int y)
{
    int f1=top[x],f2=top[y];
    ll tmp=0;
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
    if(dep[x]>dep[y]) swap(x,y);
    return tmp+query(1,w[x],w[y]);
}

int main()
{
    int n,m,a,t;
    ll b;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&c[i]);
    }
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&g[i][0],&g[i][1]);
        v[g[i][0]].push_back(g[i][1]);
        v[g[i][1]].push_back(g[i][0]);
    }
    tot=0;
    dep[0]=0;
    memset(son,0,sizeof(son));
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,tot);
    update(1,w[1],c[1]);
    for(int i=1; i<n; i++)
    {
        if(dep[g[i][0]]>dep[g[i][1]])
            swap(g[i][0],g[i][1]);
        update(1,w[g[i][1]],c[g[i][1]]);
    }
    while(m--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%lld",&a,&b);
            update2(1,w[a],w[a],b);
        }
        else if(t==2)
        {
            scanf("%d%lld",&a,&b);
            update2(1,w[a],out[a],b);
        }
        else if(t==3)
        {
            scanf("%d",&a);
            printf("%lld\n",Find(1,a));
        }
    }
    return 0;
}
