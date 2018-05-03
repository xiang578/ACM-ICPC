#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
int n,m,f[4*N],L[4*N],R[4*N],mx[4*N];

void build(int o,int l,int r)
{
    L[o]=R[o]=mx[o]=r-l+1;
    f[o]=-1;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
}

void pushup(int o,int s)
{
    L[o]=L[o*2];
    R[o]=R[o*2+1];
    if(L[o]==s-s/2)
        L[o]+=L[o*2+1];
    if(R[o]==s/2)
        R[o]+=R[o*2];
    mx[o]=max(max(mx[o*2],mx[o*2+1]),R[o*2]+L[o*2+1]);
}

void pushdw(int o,int l,int r)
{
    int mid=(l+r)/2;
    f[o*2]=f[o*2+1]=f[o];
    if(f[o]==1)
    {
        L[o*2]=R[o*2]=mx[o*2]=mid-l+1;
        L[o*2+1]=R[o*2+1]=mx[o*2+1]=r-mid;
    }
    else if(f[o]==0)
    {
        L[o*2]=R[o*2]=mx[o*2]=0;
        L[o*2+1]=R[o*2+1]=mx[o*2+1]=0;
    }
    f[o]=-1;
}

int query(int o,int l,int r,int v)
{
    int mid=(l+r)/2;
    if(mx[o]<v) return 0;
    if(l==r) return l;
    if(f[o]!=-1) pushdw(o,l,r);
    if(mx[o*2]>=v) return query(o*2,l,mid,v);
    else if(R[o*2]+L[o*2+1]>=v) return mid-R[o*2]+1;
    else return query(o*2+1,mid+1,r,v);
}

void update(int o,int l,int r,int x,int y,int v)
{
    if(f[o]!=-1) pushdw(o,l,r);
    if(x<=l&&r<=y)
    {
        f[o]=v;
        if(v)
        {
            R[o]=L[o]=mx[o]=r-l+1;
        }
        else
        {
            R[o]=L[o]=mx[o]=0;
        }
    }
    else
    {
        int mid=(l+r)/2;
        if(x<=mid) update(o*2,l,mid,x,y,v);
        if(y>mid) update(o*2+1,mid+1,r,x,y,v);
        pushup(o,r-l+1);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    build(1,1,n);
    int k,a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&a);
            int t=query(1,1,n,a);
            printf("%d\n",t);
            if(t) update(1,1,n,t,t+a-1,0);
        }
        else
        {
            scanf("%d%d",&a,&b);
            update(1,1,n,a,a+b-1,1);
        }
        //printf("%d\n",mx[1]);
    }
    return 0;
}
