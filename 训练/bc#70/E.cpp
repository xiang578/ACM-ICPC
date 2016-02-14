#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5024;
const int inf=0x7fffffff;
struct Edge
{
    int from,to,cap,flow,cost;
};
vector<Edge>edges;
vector<int>G[N];
int n,m;
int inq[N],p[N],d[N],a[N],w[100][100];;

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

int Mincost(int s,int t)
{
    int flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost));
    return cost;
}

int main()
{
    int i,j,k,u,v,c,_,tn,tm;

    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&tm,&tn);
        for(i=1;i<=tn;i++)
            for(j=1;j<=tm;j++)
            scanf("%d",&w[i][j]);

        n=tn*tm+tn;
        for(i=0; i<=5000; i++)
            G[i].clear();
        edges.clear();

        //起点，s和顾客连接
        for(i=1;i<=tn;i++)
            AddEdge(0,i,1,0);

        for(j=1;j<=tm;j++)
        {
            for(k=1;k<=tn;k++)
            {
                AddEdge(j*tn+k,n+1,1,0);
                for(i=1;i<=tn;i++)
                    AddEdge(i,j*tn+k,1,k*w[i][j]);
            }
        }
        printf("%d\n",Mincost(0,n+1));
    }
    return 0;
}
