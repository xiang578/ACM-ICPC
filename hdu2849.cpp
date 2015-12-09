#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=16;
const int MAXN=1<<16;
int g[N][N],dist[N],vis[N],use[MAXN],n,m,pe[N],low[MAXN];


double prim(int k)
{
    int sum_n,sum_m,i,u;
    for(i=0;i<n;i++)
        if(st&&(1<<i)) 
        {
            u=i;
            break;
        }
    sum_n=sum_n=0;
    sum_n+=pe[u];
    for(i=0;i<n;i++)
    {
        dist[i]=g[u][n];
    }
    vis[u]=1;
    
    return sum_n*1.0/sum_m;
}

int main()
{
    int i,j,u,v,maxn;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
            scanf("%d",&pe[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        maxn=1<<n;
        memset(use,0,sizeof(use));
        for(i=1;i<=maxn;i++)
        {
            
        }
    }
    return 0;
}
