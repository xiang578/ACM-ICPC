#include<bits/stdc++.h>
using namespace std;
const int N=2500+5;
char mp[128][128];
int xs[128][128],ys[128][128];
int nx,ny,cx[N],cy[N],g[N][N],mk[N];

int path(int u)
{
    for(int v=1; v<=ny; v++)
    {
        if(g[u][v]&&!mk[v])
        {
            mk[v]=1;
            if(cy[v]==-1||path(cy[v]))
            {
                cx[u]=v;
                cy[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int res=0;
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    for(int i=1; i<=nx; i++)
    {
        if(cx[i]==-1)
        {
            memset(mk,0,sizeof(mk));
            res+=path(i);
        }
    }
    return res;
}

int main()
{
    int i,j,_,k,n,m,st;
    scanf("%d",&_);
    for(k=1; k<=_; k++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",mp[i]);
        memset(xs,0,sizeof(xs));
        memset(ys,0,sizeof(ys));
        memset(g,0,sizeof(g));
        nx=0;
        for(i=0;i<n;i++)
        {
            st=0;
           for(j=0;j<m;j++)
           {
               if(mp[i][j]=='o')
               {
                   if(st==0) nx++;
                    xs[i][j]=nx;
                    st=1;
               }
               else if(mp[i][j]=='#') st=0;
           }
        }
        ny=0;
        for(j=0;j<m;j++)
        {
            st=0;
            for(i=0;i<n;i++)
            {
                if(mp[i][j]=='o')
               {
                   if(st==0) ny++;
                    ys[i][j]=ny;
                    st=1;
               }
               else if(mp[i][j]=='#') st=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(xs[i][j])
                    g[xs[i][j]][ys[i][j]]=1;
            }
        }
        /*for(i=0;i<=nx;i++)
        {
            for(j=0;j<=ny;j++)
            {
                printf("%d ",g[i][j]);
            }
            printf("\n");
        }*/
        printf("Case :%d\n%d\n",k,MaxMatch());
    }
    return 0;
}
