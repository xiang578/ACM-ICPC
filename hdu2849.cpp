#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=16;
const int MAXN=1<<16;
const double inf=1e10;
int g[N][N],dist[N],vis[N],use[MAXN],n,m,pe[N],low[MAXN];


double prim(int k)
{
    int sum_n,sum_m,i,j,u,w;
    for(i=0;i<n;i++)
        if(k&(1<<i))
        {
            u=i;
            break;
        }
    if(i==n) return inf;
    sum_n=sum_n=0;
    sum_n=pe[u];
    for(i=0;i<n;i++)
    {
        if((1<<i)&k)
            dist[i]=g[u][n];
        else
            dist[i]=inf;
    }
    vis[u]=1;
    for(i=0;i<n;i++)
    {
        u=-1;
        w=inf;
        for(j=0;j<n;j++)
        {
            if(vis[j]==1) continue;
            if(((1<<j)&k)==0) continue;
            if(dist[j]<w)
            {
                u=j;
                w=dist[j];
            }
        }
        if(u==-1) return inf;
        sum_m+=w;
        sum_n+=pe[u];
        vis[u]=1;
        for(i=0;i<n;i++)
        {
            if(vis[i]==1) continue;
            if(((1<<i)&k)==0) continue;
            dist[i]=min(dist[i],g[u][i]);
        }
    }
    return sum_n*1.0/sum_m;
}

int main()
{
    int i,j,u,v,maxn,st;
    double ans;
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
        ans=inf;
        for(i=1;i<=maxn;i++)
        {
            if(use[i]==0)
            {
                double tp=prim(i);
                if(ans>prim(i))
                {
                    ans=prim(i);
                    st=i;
                }
                use[i]=1;
            }
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            if((1<<i)&st==0) continue;
            if(flag) printf(" ");
            else flag++;
            printf("%d",i+1);
        }
        printf("\n");
    }
    return 0;
}
