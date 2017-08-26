//uva11297
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=1<<30;
const int maxn=2000+10;

struct IntervalTree2D
{
    int mx[maxn][maxn],mi[maxn][maxn],n,m;
    int xo,xleaf,x1,y1,x2,y2,x,y,v,vmax,vmin;

    void query1D(int o,int l,int r)
    {
        if(y1<=l&&r<=y2)
        {
            vmax=max(mx[xo][o],vmax);
            vmin=min(mi[xo][o],vmin);
        }
        else
        {
            int mid=l+(r-l)/2;
            if(y1<=mid) query1D(o*2,l,mid);
            if(mid<y2) query1D(o*2+1,mid+1,r);
        }
    }

    void query2D(int o,int l,int r)
    {
        if(x1<=l&&r<=x2)
        {
            xo=o;
            query1D(1,1,m);
        }
        else
        {
            int mid=l+(r-l)/2;
            if(x1<=mid) query2D(o*2,l,mid);
            if(mid<x2) query2D(o*2+1,mid+1,r);
        }
    }

    void modify1D(int o,int l,int r)
    {
        if(l==r)
        {
            if(xleaf)
            {
                mx[xo][o]=max(v,mx[xo][o]);
                mi[xo][o]=max(v,mi[xo][o]);
                return ;
            }
            mx[xo][o]=max(mx[xo*2][o],mx[xo*2+1][o]);
            mi[xo][o]=min(mi[xo*2][o],mi[xo*2+1][o]);
        }
        else
        {
            int mid=l+(r-l)/2;
            if(y<=mid) modify1D(o*2,l,mid);
            else modify1D(o*2+1,mid+1,r);
            mx[xo][o]=max(mx[xo][o*2],mx[xo][o*2+1]);
            mi[xo][o]=min(mi[xo][o*2],mi[xo][o*2+1]);
        }
    }

    void modify2D(int o,int l,int r)
    {
        if(l==r)
        {
            xo=o;
            xleaf=1;
            modify1D(1,1,m);
        }
        else
        {
            int mid=l+(r-l)/2;
            if(x<=mid) modify2D(o*2,l,mid);
            else modify2D(o*2+1,mid+1,r);
            xo=o;
            xleaf=0;
            modify1D(1,1,m);
        }
    }

    void query()
    {
        vmax=-inf;
        vmin=inf;
        query2D(1,1,n);
    }
    void modify()
    {
        modify2D(1,1,n);
    }
};

IntervalTree2D t;

int main()
{
    int n,i,j,x1,x2,y1,y2,x,y,v,q;
    char s[10];
    while(~scanf("%d",&n))
    {
        t.n=n;
        t.m=n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&t.v);
                t.x=i;
                t.y=j;
                t.modify();
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='q')
            {
                scanf("%d%d%d%d",&t.x1,&t.y1,&t.x2,&t.y2);
                t.query();
                printf("%d %d\n",t.vmax,t.vmin);
            }
            else
            {
                scanf("%d%d%d",&t.x,&t.y,&t.v);
                t.modify();
            }
        }
    }
    return 0;
}
