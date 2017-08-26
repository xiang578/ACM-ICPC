//Prim
//耗费矩阵e[][]，标号1~n
//返回最小生成树的权值，返回-1表示原图不连通
const int inf=0x3f3f3f3f;
const int N=1024;
bool vis[N];
int dis[N];
int prim()
{
    int i,j,u,v,w,ans=0;
    for(i=1; i<=n; i++) dis[i]=e[1][i];
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(i=2; i<=n; i++)
    {
        w=inf;
        u=-1;
        for(j=1; j<=n; j++) if(!vis[j]&&w>dis[j]) w=dis[j],u=j;
        if(u==-1) return -1;
        vis[u]=1;
        ans+=w;
        for(v=1; v<=n; v++) if(!vis[v])
                if(dis[v]>e[u][v]) dis[v]=e[u][v];
    }
    return ans;
}

