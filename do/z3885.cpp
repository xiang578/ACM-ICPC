#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=256;
const int inf=0x7fffffff;
struct Edge
{
    int from,to,cap,flow,cost;
};
vector<Edge>edges;
vector<int>G[N];
int n,m;
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

int BellmanFord(int s,int t,int &flow, int &cost)
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
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return 1;
}

void Mincost(int s,int t)
{
    int i,j,flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost));
//printf("%d\n",cost);
    for(i=0;i<G[0].size();i++)
        if(edges[G[0][i]].cap!=edges[G[0][i]].flow) cost=-1;
    for(i=1;i<=n;i++)
        for(j=0;j<G[i].size();j++)
    {
        if(edges[G[i][j]].to==t&&edges[G[i][j]].cap!=edges[G[i][j]].flow) cost=-1;
    }
    printf("%d\n",cost);
}

int main()
{
    int i,u,v,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<=n+1; i++) G[i].clear();
        edges.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b) AddEdge(i,n+1,a-b,0);
            else if(b>a) AddEdge(0,i,b-a,0);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u,v,100000+5,1);
            AddEdge(v,u,100000+5,1);
        }
        Mincost(0,n+1);
    }
    return 0;
}
