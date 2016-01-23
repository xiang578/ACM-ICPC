/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
const int N=4*100000+10;
int n,m,cnt,st[N],ed[N],vis[N],b[2*N],a[N];
ll ans;
vector<int>edge[N];
struct Tree
{
    int l,r,f;
    ll now;
}tree[10*N];

void dfs(int x)
{
    vis[x]=1;
    st[x]=cnt;
    b[cnt]=a[x];
    cnt++;
    for(int i=0;i<edge[x].size();i++)
    {
        int y=edge[x][i];
        if(!vis[y])
            dfs(y);
    }
    ed[x]=cnt;
    b[cnt]=a[x];
    cnt++;
}

void build(int o,int l,int r)
{
    tree[o].l=l;
    tree[o].r=r;
    tree[o].f=0;
    if(l==r)
    {
        tree[o].now=(long long)1<<(long long)b[l];
    }
    else
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        tree[o].now=tree[o*2].now|tree[o*2+1].now;
    }
}

void pushdown(int o)
{
    if(tree[o].f!=0)
    {
        tree[o*2].f=tree[o*2+1].f=tree[o].f;
        tree[o].f=0;
        tree[o*2].now=tree[o*2+1].now=tree[o].now;
    }
}

void update(int o,int l,int r,int val)
{
    if(l<=tree[o].l&&tree[o].r<=r)
    {
        tree[o].f=val;
        tree[o].now=(long long)1<<(long long)val;
    }
    else
    {
        pushdown(o);
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid)  update(o*2,l,r,val);
        if(r>mid) update(o*2+1,l,r,val);
        tree[o].now=tree[o*2].now|tree[o*2+1].now;
    }
}

void query(int o,int l,int r)
{
    if(tree[o].f!=0)
    {
        ans=ans|tree[o].now;
    }
    else if(l<=tree[o].l&&tree[o].r<=r)
    {
       ans=ans|tree[o].now;
    }
    else
    {
        int mid=(tree[o].l+tree[o].r)/2;
        if(l<=mid) query(o*2,l,r);
        if(r>mid) query(o*2+1,l,r);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,u,v,c,t;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
            edge[i].clear();
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        memset(vis,0,sizeof(vis));
        cnt=1;
        dfs(1);
        build(1,1,cnt-1);
        for(i=0;i<m;i++)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d%d",&u,&v);
                update(1,st[u],ed[u],v);
            }
            else
            {
                scanf("%d",&t);

                ans=0;
                query(1,st[t],ed[t]);
                u=0;
                while(ans)
                {
                    u+=ans%2;
                    ans/=2;
                }
                printf("%d\n",u);
            }
        }
    }
    return 0;
}
