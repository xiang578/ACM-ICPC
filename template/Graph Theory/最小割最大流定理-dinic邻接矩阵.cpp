//uva 10480
//先跑最大流，之后再从起点开始dfs，走没有满流的边，走到的都是s集合的，其他是t集合的。
//某一条边两个端点不再同一个集合就是割边
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N=1024;
const int inf=1<<24;

int cap[N][N];
int flow[N][N];
int n,m,s,t;
int vis[N];
int d[N];
int cur[N];
int use[N];

bool BFS()
{
    memset(vis,0,sizeof(vis));
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(cap[x][i]==0) continue;
            if(!vis[i]&&cap[x][i]>flow[x][i])
            {
                vis[i]=1;
                d[i]=d[x]+1;
                Q.push(i);
            }
        }
    }
    return vis[t];
}

int DFS(int x,int a)
{
    if(x==t||a==0) return a;
    int res=0,f;
    for(int i=1; i<=n; i++)
    {
        if(cap[x][i]==0) continue;
        if(d[x]+1==d[i]&&(f=DFS(i,min(a,cap[x][i]-flow[x][i])))>0)
        {
            flow[x][i]+=f;
            flow[i][x]-=f;
            res+=f;
            a-=f;
            if(a==0) break;
        }
    }
    return res;
}

int Maxflow(int st,int ed)
{
    int res=0;
    while(BFS())
    {
        memset(cur,0,sizeof(cur));
        res+=DFS(st,inf);
    }
    return res;
}

void dfs(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(cap[x][i]&&cap[x][i]>flow[x][i]&&use[i]==0)
        {
            use[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    int i,j,u,v,c;
    int x[N],y[N];
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        memset(flow,0,sizeof(flow));
        memset(cap,0,sizeof(cap));
        s=1;
        t=2;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            x[i]=u;
            y[i]=v;
            cap[u][v]=cap[v][u]=c;
        }
        Maxflow(s,t);
        //printf("%d\n",);
        memset(use,0,sizeof(use));
        use[1]=1;
        dfs(1);
        for(i=0;i<m;i++)
        {
            if(use[x[i]]+use[y[i]]==1)
            {
                printf("%d %d\n",x[i],y[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
