#include<bits/stdc++.h>
using namespace std;
const int N=500000+10;
vector<int>v[N];
int in[N],out[N],f[N],vis[N],n,tot,ans;

void dfs(int x,int fa)
{
    vis[x]=1;
    in[x]=++tot;
    f[x]=fa;
    for(int i=0; i<v[x].size(); i++)
    {
        if(vis[v[x][i]]==0)
        {
            dfs(v[x][i],x);
        }
    }
    out[x]=tot;
}

struct Tree
{
    int l,r,f,sum;
}tree[4*N];

void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].f=-1;
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
    if(tree[o].f!=-1)
    {
        tree[o*2].f=tree[o*2+1].f=tree[o].f;
        tree[o*2].sum=(tree[o*2].r-tree[o*2].l+1)*tree[o].f;
        tree[o*2+1].sum=(tree[o*2+1].r-tree[o*2+1].l+1)*tree[o].f;
        tree[o].f=-1;
    }
}

void update(int o,int l,int r,int val)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        tree[o].f=val;
        tree[o].sum=val*(tree[o].r-tree[o].l+1);
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update(o*2,l,r,val);
        if(r>mid) update(o*2+1,l,r,val);
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

int query(int o,int l,int r)
{
    if(tree[o].f!=-1)
    {
        int maxl=max(l,tree[o].l);
        int minr=min(r,tree[o].r);
        return tree[o].f*(minr-maxl+1);
    }
    if(l<=tree[o].l&&tree[o].r<=r)
    {
       return tree[o].sum;
    }
    else
    {
        int ret=0;
        //pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid) ret+=query(o*2,l,r);
        if(r>mid) ret+=query(o*2+1,l,r);
        return ret;
    }
}

int main()
{
    int a,b,q,ci,vi;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        v[i].clear();
    for(int i=0; i<n-1; i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    tot=0;
    dfs(1,0);
    build(1,1,tot);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d%d",&ci,&vi);
        if(ci==1)
        {
            if(query(1,in[vi],out[vi])<(out[vi]-in[vi]+1)&&f[vi]!=0)
                update(1,in[f[vi]],in[f[vi]],0);
            update(1,in[vi],out[vi],1);
        }
        else if(ci==2)
        {
            update(1,in[vi],in[vi],0);
        }
        else if(ci==3)
        {
            if(query(1,in[vi],out[vi])<(out[vi]-in[vi]+1)) puts("0");
            else puts("1");
        }
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N=500000+10;
vector<int>v[N];
int in[N],out[N],f[N],vis[N],n,tot,ans;

void dfs(int x,int fa)
{
    vis[x]=1;
    in[x]=++tot;
    f[x]=fa;
    for(int i=0; i<v[x].size(); i++)
    {
        if(vis[v[x][i]]==0)
        {
            dfs(v[x][i],x);
        }
    }
    out[x]=tot;
}

struct Tree
{
    int l,r,f,sum;
}tree[4*N];

void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].f=-1;
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
    if(tree[o].f!=-1)
    {
        tree[o*2].f=tree[o*2+1].f=tree[o].f;
        tree[o*2].sum=(tree[o*2].r-tree[o*2].l+1)*tree[o].f;
        tree[o*2+1].sum=(tree[o*2+1].r-tree[o*2+1].l+1)*tree[o].f;
        tree[o].f=-1;
    }
}

void update(int o,int l,int r,int val)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        tree[o].f=val;
        tree[o].sum=val*(tree[o].r-tree[o].l+1);
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update(o*2,l,r,val);
        if(r>mid) update(o*2+1,l,r,val);
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

int query(int o,int l,int r)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
       return tree[o].sum;
    }
    else
    {
        int ret=0;
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid) ret+=query(o*2,l,r);
        if(r>mid) ret+=query(o*2+1,l,r);
        return ret;
    }
}

int main()
{
    int a,b,q,ci,vi;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        v[i].clear();
    for(int i=0; i<n-1; i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    tot=0;
    dfs(1,0);
    build(1,1,tot);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d%d",&ci,&vi);
        if(ci==1)
        {
            if(query(1,in[vi],out[vi])<(out[vi]-in[vi]+1)&&f[vi]!=0)
                update(1,in[f[vi]],in[f[vi]],0);
            update(1,in[vi],out[vi],1);
        }
        else if(ci==2)
        {
            update(1,in[vi],in[vi],0);
        }
        else if(ci==3)
        {
            if(query(1,in[vi],out[vi])<(out[vi]-in[vi]+1)) puts("0");
            else puts("1");
        }
    }
    return 0;
}*/
