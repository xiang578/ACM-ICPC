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
int inq[N],p[N],d[N],a[N];

void AddEdge(int from, int to,int cap, int cost)
{
    //printf("%d %d\n",from,to);
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
        //printf("##### %d\n",u);
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
    //printf("!!!! %d\n",d[i]);
    if(d[t]==inf) return 0;
    flow+=a[t];
    cost+=d[t]*a[t];
    u=t;
    while(u!=0)
    {
        //printf("%d %d\n",edges[p[u]].to,edges[p[u]].from);
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }

    return 1;
}

int Mincost(int s,int t,int n)
{
    int flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost,n))
    {
        //printf("%d\n",cost);
    };
    return cost;
}

void init(int n)
{
    for(int i=0; i<=n+1; i++) G[i].clear();
    edges.clear();
}

int main()
{
    int i,u,v,c,n,m,k;
    int _,cas=0;
    char str[20][20];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int e=2*n*m+4,s=0,t=2*n*m+3;
        init(e);
        for(i=0; i<n; i++)
        {
            scanf("%s",str[i]);
        }
        printf("Case %d : ",++cas);
        if(min(n,m)>k)
        {
            printf("-1\n");
            continue;
        }
        AddEdge(s,2*n*m+1,k,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                AddEdge(s,i*m+j+1,1,0);
                AddEdge(i*m+j+n*m+1,t,1,0);
                AddEdge(2*n*m+1,i*m+j+n*m+1,1,0);
                for(int a=i+1; a<n; a++)
                {

                    int cost=0;
                    if(str[i][j]==str[a][j])
                    {
                        cost-=str[i][j]-'0';
                    }
                    cost+=abs(i-a)-1;
                    AddEdge(i*m+j+1,1+a*m+j+n*m,1,cost);
                }


                for(int b=j+1; b<m; b++)
                {
                    int cost=0;
                    if(str[i][j]==str[i][b])
                    {
                        cost-=str[i][j]-'0';
                    }
                    cost+=abs(j-b)-1;
                    AddEdge(1+i*m+j,1+i*m+b+n*m,1,cost);
                }
            }
        }
        printf("%d\n",-Mincost(s,t,e));
    }
    return 0;
}
