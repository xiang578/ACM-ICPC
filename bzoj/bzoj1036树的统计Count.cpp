#include<bits/stdc++.h>
using namespace std;
const long long inf=1<<30;
const int N=40000+10;
typedef long long ll;

struct
{
    int a,b;
}g[N];

struct
{
    int l,r;
    ll sum,mx;
}tree[4*N];
vector<int>v[N];
int n,fa[N],dep[N],sz[N],son[N],w[N],tot,top[N];
ll cost[N],t;

void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].mx=-inf;
    tree[o].sum=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
    }
}

void update(int o,int k,int val)
{
    if(k==tree[o].l&&tree[o].r==k)
    {
        tree[o].mx=tree[o].sum=val;
    }
    else
    {
        int mid=(tree[o].l+tree[o].r)/2;
        if(k<=mid)  update(o*2,k,val);
        else update(o*2+1,k,val);
        tree[o].mx=max(tree[o*2].mx,tree[o*2+1].mx);
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

ll querymax(int o,int l,int r)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
       return tree[o].mx;
    }
    else
    {
        int mid=(tree[o].l+tree[o].r)/2;
        if(r<=mid) return querymax(o*2,l,r);
        else if(l>mid) return querymax(o*2+1,l,r);
        else return max(querymax(o*2,l,mid),querymax(o*2+1,mid+1,r));
    }
}

ll querysum(int o,int l,int r)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
       return tree[o].sum;
    }
    else
    {
        int ret=0;
        int mid=(tree[o].l+tree[o].r)/2;
        if(r<=mid) return querysum(o*2,l,r);
        else if(l>mid) return querysum(o*2+1,l,r);
        else return querysum(o*2,l,mid)+querysum(o*2+1,mid+1,r);
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
    w[x]=++tot;
    if(son[x]==0) return ;
    dfs2(son[x],tp);
    int y;
    for(int i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(y!=son[x]&&y!=fa[x])
            dfs2(y,y);
    }
}

ll Findmax(int x,int y)
{
    int f1=top[x],f2=top[y];
    ll tmp=-inf;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(x,y);
        }
        tmp=max(tmp,querymax(1,w[f1],w[x]));
        x=fa[f1];
        f1=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return max(tmp,querymax(1,w[x],w[y]));
}

ll Findsum(int x,int y)
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
        tmp+=querysum(1,w[f1],w[x]);
        x=fa[f1];
        f1=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return tmp+querysum(1,w[x],w[y]);
}

int main()
{
    int _,a,b;
    char s[1024];
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++)
            v[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&g[i].a,&g[i].b);
            v[g[i].a].push_back(g[i].b);
            v[g[i].b].push_back(g[i].a);
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&cost[i]);
        dep[0]=0;
        memset(son,0,sizeof(son));
        tot=0;
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,tot);
        update(1,w[1],cost[1]);
        for(int i=1;i<n;i++)
        {
            if(dep[g[i].a]>dep[g[i].b])
                swap(g[i].a,g[i].b);
            update(1,w[g[i].b],cost[g[i].b]);
        }
        scanf("%d",&_);
        while(_--)
        {
            scanf("%s",s);
            if(s[1]=='M')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",Findmax(a,b));
            }
            else if(s[1]=='S')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",Findsum(a,b));
            }
            else if(s[1]=='H')
            {
                scanf("%d%lld",&a,&t);
                update(1,w[a],t);
            }
        }
    }
    return 0;
}
