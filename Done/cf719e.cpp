#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1000000007;
int m,n;
ll lazy[4*N],num[N];
struct node
{
    ll a[2][2];
    node()
    {
        memset(a,0,sizeof(a));
    }
}p[4*N],q[4*N];

node add(node n1,node n2)
{
    node tmp;
    tmp.a[0][0]=(n1.a[0][0]+n2.a[0][0])%mod;
    tmp.a[0][1]=(n1.a[0][1]+n2.a[0][1])%mod;
    tmp.a[1][0]=(n1.a[1][0]+n2.a[1][0])%mod;
    tmp.a[1][1]=(n1.a[1][1]+n2.a[1][1])%mod;
    return tmp;
}

node mul(node n1,node n2)
{
    node tmp;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                tmp.a[i][j]=(tmp.a[i][j]+n1.a[i][k]*n2.a[k][j])%mod;
            }
        }
    }
    return tmp;
}

node fpow(ll x)
{
    node c;
    c.a[0][0]=c.a[0][1]=c.a[1][0]=1;
    c.a[1][1]=0;
    node t;
    for(int i=0;i<2;i++)
        t.a[i][i]=1;
    while(x)
    {
        if(x&1)
            t=mul(t,c);
        c=mul(c,c);
        x>>=1;
    }
    return t;
}

void build(int o,int l,int r)
{
    lazy[o]=0;
    q[o].a[0][0]=1;q[o].a[0][1]=0;q[o].a[1][0]=0;q[o].a[1][1]=1;
    if(l==r)
    {
        p[o]=fpow(num[l]);
        return ;
    }
    build(o*2,l,(l+r)/2);
    build(o*2+1,(l+r)/2+1,r);
    p[o]=add(p[o*2],p[o*2+1]);
}

void pushdw(int o)
{
    if(lazy[o])
    {
        lazy[o*2]=lazy[o*2+1]=1;
        q[o*2]=mul(q[o*2],q[o]);
        q[o*2+1]=mul(q[o*2+1],q[o]);
        p[o*2]=mul(p[o*2],q[o]);
        p[o*2+1]=mul(p[o*2+1],q[o]);
        q[o].a[0][0]=1;q[o].a[0][1]=0;q[o].a[1][0]=0;q[o].a[1][1]=1;
        lazy[o]=0;
    }
}
void update(int o,int l,int r,int x,int y,node val)
{
    if(x<=l&&r<=y)
    {
        lazy[o]=1;
        q[o]=mul(q[o],val);
        p[o]=mul(p[o],val);
    }
    else
    {
        int m=(l+r)/2;
        pushdw(o);
        if(x<=m) update(o*2,l,m,x,y,val);
        if(y>m) update(o*2+1,m+1,r,x,y,val);
        p[o]=add(p[o*2],p[o*2+1]);
    }
}

node query(int o,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {
        return p[o];
    }
    else
    {
        pushdw(o);
        int m=(l+r)/2;
        node ret;
        if(x<=m) ret=add(ret,query(o*2,l,m,x,y));
        if(y>m) ret=add(ret,query(o*2+1,m+1,r,x,y));
        return ret;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {

        int l,r,k;
        ll x;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
        }
        build(1,1,n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&k,&l,&r);
            if(k==1)
            {
                scanf("%lld",&x);
                update(1,1,n,l,r,fpow(x));
            }
            else
            {
                node c;
                c.a[0][0]=0;
                c.a[0][1]=0;
                c.a[1][0]=1;
                c.a[1][1]=0;
                node ans=mul(query(1,1,n,l,r),c);
                printf("%lld\n",ans.a[0][0]);
            }
        }
    }
    return 0;
}

