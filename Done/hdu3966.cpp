#pragma comment(linker,"/STACK:100000000,100000000")
#include<bits/stdc++.h>
using namespace std;
const int N=50000+10;
struct
{
    int f,l,r,sum;
}tree[4*N];

int g[N][2],c[N],top[N],fa[N],dep[N],son[N],sz[N],w[N],tot;
vector<int>v[N];

void dfs1(int x,int f)
{
    int y,m=0;
    dep[x]=dep[f]+1;
    fa[x]=f;
    sz[x]=1;
    for(int i=0;i<v[x].size();i++)
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
    w[x]=++tot;
    if(son[x]==0) return ;
    dfs2(son[x],tp);
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(y==fa[x]||y==son[x]) continue;
        dfs2(y,y);
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
    if(tree[o].l==tree[o].r) return ;
    if(tree[o].f!=0)
    {
        tree[o*2].f+=tree[o].f;
        tree[o*2+1].f+=tree[o].f;
        tree[o*2].sum=tree[o*2].sum+(tree[o*2].r-tree[o*2].l+1)*tree[o].f;
        tree[o*2+1].sum=tree[o*2+1].sum+(tree[o*2+1].r-tree[o*2+1].l+1)*tree[o].f;
        tree[o].f=0;
        tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
    }
}

void update(int o,int k,int val)
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

void update2(int o,int l,int r,int val)
{
    if(l==tree[o].l&&tree[o].r==r)
    {
        pushdown(o);
        tree[o].f=val;
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

int query(int o,int k)
{
    if(k==tree[o].l&&tree[o].r==k)
    {
        return tree[o].sum;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(k<=mid)  query(o*2,k);
        else query(o*2+1,k);
    }
}

void change(int x,int y,int val)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(x,y);
        }
        update2(1,w[f1],w[x],val);
        x=fa[f1];
        f1=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update2(1,w[x],w[y],val);
}

int main()
{
    int n,m,p,a,b,t;
    char s[10];
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
        }
        for(int i=1;i<n;i++)
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
        for(int i=1;i<n;i++)
        {
            if(dep[g[i][0]]>dep[g[i][1]])
                swap(g[i][0],g[i][1]);
            update(1,w[g[i][1]],c[g[i][1]]);
        }
        while(p--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d",&t);
                printf("%d\n",query(1,w[t]));
            }
            else if(s[0]=='D')
            {
                scanf("%d%d%d",&a,&b,&t);
                change(a,b,-t);
            }
            else if(s[0]=='I')
            {
                scanf("%d%d%d",&a,&b,&t);
                change(a,b,t);
            }
        }
    }
    return 0;
}
