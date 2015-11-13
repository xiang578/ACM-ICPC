//求最小生成树，用maxcost保存i到j的路径中最大边权值
//求完后枚举所有不在MST中的边，替换最大边权的边，更新答案
const int MAXN=1024;
const int INF=0x7fffffff;

int vis[MAXN],use[MAXN][MAXN],pre[MAXN],dist[MAXN],g[MAXN][MAXN];
int maxcost[MAXN][MAXN];//表示最小生成树中i到j的路径中最大边权值

int prim(int n)
{
    int ret=0,st=0;
    memset(vis,0,sizeof(vis));
    memset(use,0,sizeof(use));
    memset(maxcost,0,sizeof(maxcost));
    vis[st]=1;
    pre[st]=-1;
    for(int i=1;i<n;i++)
    {
        dist[i]=g[i][st];
        pre[i]=st;
    }
    dist[st]=0;
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dist[j]<minc)
            {
                minc=dist[j];
                p=j;
            }
        }
        if(minc==INF) return -1;
        ret+=minc;
        vis[p]=1;
        use[p][pre[p]]=use[pre[p]][p]=1;
        for(int j=0;j<n;j++)
        {
            if(vis[j])
                maxcost[j][p]=maxcost[p][j]=max(maxcost[j][pre[p]],dist[p]);
            if(!vis[j]&&dist[j]>g[p][j])
            {
                dist[j]=g[p][j];
                pre[j]=p;
            }
        }
    }
    return ret;
}
