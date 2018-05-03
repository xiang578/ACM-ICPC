#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100;
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
    if(d[t]>=0) return 0;
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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main()
{
    int b[100][100],ans,p[100][100];
    int tn,tm,i,j,u,v,c,s,t,k,_;
    scanf("%d",&_);
    for(int __=1; __<=_; __++)
    {
        scanf("%d%d%d",&tn,&tm,&k);
        ans=0;
        int cnt=1;
        for(i=0; i<tn; i++)
        {
            for(j=0; j<tm; j++)
            {
                scanf("%d",&b[i][j]);
                ans+=b[i][j]*b[i][j];
                p[i][j]=cnt;
                cnt++;
            }
        }
        s=0;
        t=cnt;
        n=cnt;
        edges.clear();
        for(i=0; i<=n+1; i++)
            G[i].clear();
        for(i=0; i<tn; i++)
        {
            for(j=0; j<tm; j++)
            {
                if(i%2==j%2)
                {
                    for(int f=1; f<=k; f++)
                        AddEdge(s,p[i][j],1,2*f-1-2*b[i][j]);
                    for(int f=0;f<4;f++)
                    {
                        int x=i+dx[f];
                        int y=j+dy[f];
                        if(x<0||x>=tn||y>=tm||y<0) continue;
                        AddEdge(p[i][j],p[x][y],inf,0);
                    }
                }
                else
                {
                    for(int f=1; f<=k; f++)
                        AddEdge(p[i][j],t,1,2*f-1-2*b[i][j]);
                }

            }
        }
        printf("Case %d: %d\n",__,ans+Mincost(s,t));
    }
    return 0;
}
