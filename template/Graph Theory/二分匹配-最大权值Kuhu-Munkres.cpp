#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N=1024;
const int inf=100000000;

int n,m,w[N][N],aug,mat[N],lx[N],ly[N];
int visx[N],visy[N],slack[N];

int dfs(int u)
{
    visx[u]=1;
    for(int v=1;v<=m;v++)
    {
        int t=lx[u]+ly[v]-w[u][v];
        if(t) slack[v]=min(slack[v],t);
        else
        {
            if(!visy[v])
            {
                visy[v]=1;
                if(mat[v]==-1||dfs(mat[v]))
                {
                    mat[v]=u;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int km()
{
    int i,j,ret=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        lx[i]=max(lx[i],w[i][j]);
    for(int x=1;x<=n;x++)
    {
        for(i=0;i<=m;i++) slack[i]=inf;
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(dfs(x)) break;
            aug=inf;
            for(i=1;i<=m;i++)
                if(!visy[i]) aug=min(aug,slack[i]);
            for(i=1;i<=n;i++)
                if(visx[i]) lx[i]-=aug;
            for(i=1;i<=m;i++)
                if(visy[i]) ly[i]+=aug;
                else slack[i]-=aug;
        }
    }
    int cnt=0;
    for(i=1;i<=m;i++)
    {
        if(mat[i]==-1||w[mat[i]][i]==-inf) continue;
        cnt++;
        ret+=w[mat[i]][i];
    }
    if(cnt!=n) return -1;
    return ret;
}

void init()
{
    memset(mat,-1,sizeof(mat));
    memset(lx,-0x7f,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(w,-0x7f,sizeof(w));
}

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        init();
        m=n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&w[i][j]);
            }
        }
        printf("%d\n",km());
    }
}

