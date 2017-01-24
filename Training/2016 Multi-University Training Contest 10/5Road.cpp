#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000+10;
struct node
{
    int x,t,f;
} p[4*N];

ll sum[4*N+10],a[N];
int tot,n,m,mi[4*N+10],ma[4*N+10];

int l[N],r[N];
int cmp(node n1,node n2)
{
    if(n1.t==n2.t)
        return n1.f<n2.f;
    else
        return n1.t<n2.t;
}
void down(int o)
{
    if(mi[o]!=-1)
    {
        if(mi[o*2]==-1)
            mi[o*2]=mi[o];
        else
            mi[o*2]=min(mi[o],mi[o*2]);

        if(mi[o*2+1]==-1)
            mi[o*2+1]=mi[o];
        else
            mi[o*2+1]=min(mi[o],mi[o*2+1]);
    }
    if(ma[o]!=-1)
    {
        if(ma[o*2]==-1)
            ma[o*2]=ma[o];
        else
            ma[o*2]=max(ma[o],ma[o*2]);
        if(ma[o*2+1]==-1)
            ma[o*2+1]=ma[o];
        else
            ma[o*2+1]=max(ma[o],ma[o*2+1]);
    }
    mi[o]=ma[o]=-1;
}

void update(int o,int l,int r,int x,int y,int v)
{
    //printf("%d %d\n",l,r);
    int mid=l+(r-l)/2;
    if(x<=l&&y>=r)
    {
        if(mi[o]==-1)
            mi[o]=v;
        else
            mi[o]=min(mi[o],v);

        if(ma[o]==-1)
            ma[o]=v;
        else
            ma[o]=max(ma[o],v);

    }
    else
    {
        down(o);
        if(x<=mid) update(o*2,l,mid,x,y,v);
        if(y>mid)  update(o*2+1,mid+1,r,x,y,v);
        if(mi[o*2]==mi[o*2+1]) mi[o]=mi[o*2];
        else mi[o]=-1;
        if(ma[o*2]==ma[o*2+1]) ma[o]=ma[o*2];
        else ma[o]=-1;
    }
}

void query(int o,int l,int r)
{
    if(l==r)
    {
        if(mi[o]!=-1)
        {
            node tmp;
            tmp.x=l;
            tmp.t=mi[o];
            tmp.f=1;
            p[tot]=tmp;
            tot++;
        }

        if(ma[o]!=-1)
        {
            node tmp;
            tmp.x=l;
            tmp.t=ma[o]+1;
            tmp.f=0;
            p[tot]=tmp;
            tot++;
        }
        //printf("    %lld %lld\n",mi[o],ma[o]);
    }
    else
    {
        down(o);
        int mid=l+(r-l)/2;
        query(o*2,l,mid);
        query(o*2+1,mid+1,r);
    }
}

void updatesum(int o,int l,int r,int x,ll v)
{
    if(l==r)
    {
        sum[o]+=v;
        // printf("%lld\n",sum[o]);
    }
    else
    {
        int mid=l+(r-l)/2;
        if(x<=mid) updatesum(o*2,l,mid,x,v);
        else updatesum(o*2+1,mid+1,r,x,v);
        sum[o]=sum[o*2]+sum[o*2+1];
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<n; i++) scanf("%lld",&a[i]);
        memset(sum,0,sizeof(sum));
        memset(ma,0xff,sizeof(ma));
        memset(mi,0xff,sizeof(mi));
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            if(l[i]>r[i]) swap(l[i],r[i]);
            r[i]--;
            update(1,1,n-1,l[i],r[i],i);
        }
        tot=0;
        query(1,1,n-1);
        sort(p,p+tot,cmp);
        //printf("%d\n",tot);
        int j=0;
        for(int i=1; i<=m; i++)
        {
            while(p[j].t==i)
            {
                if(p[j].f==0) updatesum(1,1,n-1,p[j].x,-a[p[j].x]);
                else updatesum(1,1,n-1,p[j].x,a[p[j].x]);
                j++;
                if(j>=tot) break;
            }
            printf("%lld\n",sum[1]);
        }
    }
    return 0;
}
