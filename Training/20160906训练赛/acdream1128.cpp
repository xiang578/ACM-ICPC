//poj 2135 最小费用最大流
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e6+10;
const int inf=0x3fffffff;
struct Edge
{
    int from,to,cap,flow,cost;
};
vector<Edge>edges;
vector<int>G[N];
int inq[N],p[N],d[N],a[N];

void AddEdge(int from, int to,int cap, int cost)
{
    Edge tp;
    tp.from=from,tp.to=to,tp.cap=cap,tp.flow=0,tp.cost=cost;
    edges.push_back(tp);

    tp.from=to,tp.to=from,tp.cap=0,tp.flow=0,tp.cost=-cost;
    edges.push_back(tp);

    int g=edges.size();
    G[from].push_back(g-2);
    G[to].push_back(g-1);
}

int BellmanFord(int s,int t,int &flow, int &cost,int n)
{
    int i,j,u;
    for(i=0; i<=n+1; i++) d[i]=inf;
    memset(inq,0,sizeof(inq));
    d[s]=0;
    inq[s]=1;
    p[s]=0;
    a[s]=inf;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        inq[u]=0;
        for(i=0; i<G[u].size(); i++)
        {
            Edge &e=edges[G[u][i]];
            if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
            {
                d[e.to]=d[u]+e.cost;
                p[e.to]=G[u][i];
                a[e.to]=min(a[u],e.cap-e.flow);
                if(!inq[e.to])
                {
                    Q.push(e.to);
                    inq[e.to]=1;
                }
            }
        }
    }
    if(d[t]==inf) return 0;
    flow+=a[t];
    cost+=d[t]*a[t];
    u=t;
    while(u!=0)
    {
        //printf("%d\n",u);
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return 1;
}

int Mincost(int s,int t,int n)
{
    int flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost,n));
    printf("%d %d\n",flow,cost);
    return cost;
}
int mp[120][120],id[120][120],sum[120],all;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int main()
{
    int n,m,u,v,s,t,c1,c2,now,ans;
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d%d",&c1,&c2);
        memset(sum,0,sizeof(sum));
        all=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&mp[i][j]);
                sum[i]+=mp[i][j];
                id[i][j]=(i-1)*m+j;
            }
            all+=sum[i];
        }
        s=0,t=n*m+1;
        ans=inf;
        for(int now=0; now<=all; now++)
        {
            if(now%n!=0||now%m!=0) continue;
            edges.clear();
            for(int i=0; i<N; i++) G[i].clear();
            for(int i=1; i<=m; i++)
            {
                AddEdge(n*m+1+n+i,t,now/m,0);
            }
            for(int i=1; i<=n; i++)
            {
                AddEdge(n*m+1+i,t,max(sum[i]-now/n,0),0);
            }

            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    AddEdge(s,id[i][j],mp[i][j],0);
                    AddEdge(id[i][j],n*m+1+n+j,mp[i][j],0);
                    AddEdge(id[i][j],n*m+1+i,mp[i][j],c2);
                    for(int k=0; k<4; k++)
                    {
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x<1||x>n||y>m||y<1) continue;
                        AddEdge(id[i][j],id[x][y],mp[i][j],c1);
                    }
                }
            }

            ans=min(ans,Mincost(s,t,n*m+1+n+m));
            printf("%d %d\n",now,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
