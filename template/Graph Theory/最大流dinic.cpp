//poj 1273 ×î´óÁ÷
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N=1024;
const int inf=1<<24;

struct Edge
{
    int from,to,cap,flow;
};
vector<Edge>edges;
vector<int>G[N];
int s,t;
int vis[N];
int d[N];
int cur[N];

void AddEdge(int from,int to,int cap)
{
    Edge tp;
    tp.from=from,tp.to=to,tp.cap=cap,tp.flow=0;
    edges.push_back(tp);

    tp.from=to,tp.to=from,tp.cap=0,tp.flow=0;
    edges.push_back(tp);

    int g_size=edges.size();
    G[from].push_back(g_size-2);
    G[to].push_back(g_size-1);
}

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
        for(int i=0; i<G[x].size(); i++)
        {
            Edge &e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

int DFS(int x,int a)
{
    if(x==t||a==0) return a;
    int flow=0,f;
    for(int &i=cur[x]; i<G[x].size(); i++)
    {
        Edge &e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
        {
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
     if(!flow) d[x] = -1;
    return flow;
}

int Maxflow(int st,int ed)
{
    int flow=0;
    while(BFS())
    {
        memset(cur,0,sizeof(cur));
        flow+=DFS(st,inf);
    }
    return flow;
}

int main()
{
    int n,m,u,v,c;;
    while(~scanf("%d%d",&n,&m))
    {
         edges.clear();
        for(int i=0; i<N; i++) G[i].clear();
        s=1;t=n;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        printf("%d\n",Maxflow(s,t));
    }
    return 0;
}
