#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll sum[4*N],mx[4*N],mi[4*N],cover[4*N],f[4*N];

void pushup(int o)
{
    mx[o]=max(mx[o*2],mx[o*2+1]);
    mi[o]=min(mi[o*2],mi[o*2+1]);
    sum[o]=sum[o*2]+sum[o*2+1];
}

void pushdw(int o,int l,int r)
{
    if(cover[o]!=0)
    {
        int m=(l+r)/2;

        cover[o*2]=cover[o*2+1]=cover[o];
        mi[o*2]=mx[o*2]=cover[o];
        mi[o*2+1]=mx[o*2+1]=cover[o];

        sum[o*2]=cover[o]*(m-l+1);
        sum[o*2+1]=cover[o]*(r-m);
        f[o*2+1]=f[o*2]=0;
        cover[o]=0;
    }
    if(f[o]!=0)
    {
        int m=(l+r)/2;
        f[o*2]+=f[o];
        f[o*2+1]+=f[o];
        mx[o*2]+=f[o];
        mx[o*2+1]+=f[o];
        mi[o*2]+=f[o];
        mi[o*2+1]+=f[o];

        sum[o*2]+=f[o]*(m-l+1);
        sum[o*2+1]+=f[o]*(r-m);
        f[o]=0;
    }
}

void build(int o,int l,int r)
{
    f[o]=cover[o]=0;
    if(l==r)
    {
        scanf("%lld",&sum[o]);
        mx[o]=mi[o]=sum[o];
    }
    else
    {
        int m=(l+r)/2;
        build(o*2,l,m);
        build(o*2+1,m+1,r);
        pushup(o);
    }
}

void add(int o,int l,int r,int x,int y,ll v)
{
    if(x<=l&&r<=y)
    {
        sum[o]+=(ll)v*(r-l+1);
        f[o]+=v;
        mx[o]+=v;
        mi[o]+=v;
    }
    else
    {
        int m=(l+r)/2;
        pushdw(o,l,r);
        if(x<=m) add(o*2,l,m,x,y,v);
        if(y>m) add(o*2+1,m+1,r,x,y,v);
        pushup(o);
    }
}

void update(int o,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {

        if(mx[o]==1) return ;
        if(l==r)
        {
            sum[o]=floor(sqrt(mx[o]));
            mx[o]=mi[o]=sum[o];
            return ;
        }
        if(mx[o]==mi[o])
        {
            mx[o]=floor(sqrt(mx[o]));
            f[o]-=mi[o]-mx[o];
            mi[o]=mx[o];
            sum[o]=(ll)mx[o]*(r-l+1);
            return ;
        }
        else if(mx[o]-mi[o]==1)
        {
            ll nx=floor(sqrt(mx[o]));
            ll ni=floor(sqrt(mi[o]));
            if(nx==ni)
            {
                mx[o]=mi[o]=nx;
                sum[o]=(ll)nx*(r-l+1);
                cover[o]=nx;
                f[o]=0;
            }
            else
            {
                ll numx=sum[o]-(ll)(r-l+1)*mi[o];
                ll numi=(r-l+1)-numx;
                sum[o]=numx*nx+numi*ni;
                f[o]-=mx[o]-nx;
                mx[o]=nx;
                mi[o]=ni;
            }
            return ;
        }
        pushdw(o,l,r);
        int m=(l+r)/2;
        update(o*2,l,m,x,y);
        update(o*2+1,m+1,r,x,y);
        pushup(o);
        return ;
    }
    pushdw(o,l,r);
    int m=(l+r)/2;
    if(x<=m) update(o*2,l,m,x,y);
    if(y>m) update(o*2+1,m+1,r,x,y);
    pushup(o);
}

ll query(int o,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {
        return sum[o];
    }
    else
    {
        pushdw(o,l,r);
        int m=(l+r)/2;
        ll ans=0;
        if(x<=m) ans+=query(o*2,l,m,x,y);
        if(y>m) ans+=query(o*2+1,m+1,r,x,y);
        return ans;
    }
}

int main()
{
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        for(int i=0; i<m; i++)
        {
            int k,l,r;
            ll a;
            scanf("%d%d%d",&k,&l,&r);
            if(k==1)
            {
                scanf("%lld",&a);
                add(1,1,n,l,r,a);
            }
            else if(k==2)
            {
                update(1,1,n,l,r);
            }
            else
            {
                printf("%lld\n",query(1,1,n,l,r));
            }
        }
    }
    return 0;
}
