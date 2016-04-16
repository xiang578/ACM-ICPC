/*#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int MAXM = 300000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
} edge[MAXM];
int head[MAXN],tol,g[1024][1024];
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost )
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}

//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}


int main()
{
    char st[1024];
    int i,m,x,s,t,_,n,p[1024],girl[1024],cost,flow;
    scanf("%d",&_);
    while(_--)
    {

        scanf("%d",&n);
        init(n+2);
        s=0;
        t=n+1;
        scanf("%s",st);
        for(i=0; i<n; i++)
            p[i+1]=st[i]-'0';
        scanf("%s",st);
        for(i=0; i<n; i++)
            girl[i+1]=st[i]-'0';
        memset(g,0,sizeof(g));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&x);
                g[x][i]=g[i][x]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(p[i]) addedge(s,i,1,0);
            else addedge(i,t,1,0);
        }
        for(i=1;i<=n;i++)
        {
            if(!p[i]) continue;
            for(int j=1;j<=n;j++)
            {
                if(p[j]||i==j||g[i][j]) continue;
                addedge(i,j,1,girl[i]+girl[j]);
            }
        }
        flow=minCostMaxflow(s,t,cost);
        printf("%d %d\n",flow,2*flow-cost);
        for(i=1;i<=n;i++)
        {
            if(!p[i]) continue;
            for(int j = head[i]; j != -1; j = edge[j].next)
            {
                if(edge[j].cap==edge[j].flow&&edge[j].to!=0)
                {
                    printf("%d %d\n",i,edge[j].to);
                }
            }
        }
    }
    return 0;
}*/

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
int inq[N],p[N],d[N],a[N],b[1024],gt[1024][1024];

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
    int flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost));
    printf("%d %d\n",flow,2*flow-cost);
    for(int i=1;i<=n;i++)
    {
        if(!b[i]) continue;
        for(int j=0;j<G[i].size();j++)
        {
            int u=G[i][j];
            if(edges[u].flow!=edges[u].cap) continue;
            u=edges[u].to;
            if(u==0) continue;
            printf("%d %d\n",i,u);
        }
    }
}

int main()
{
    char st[1024];
    int i,x,s,t,_,girl[1024],cost,flow;
    scanf("%d",&_);
    while(_--)
    {

        scanf("%d",&n);
        for(i=0; i<=n+1; i++) G[i].clear();
        edges.clear();
        s=0;
        t=n+1;
        scanf("%s",st);
        for(i=0; i<n; i++)
            b[i+1]=st[i]-'0';
        scanf("%s",st);
        for(i=0; i<n; i++)
            girl[i+1]=st[i]-'0';
        memset(gt,0,sizeof(gt));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&x);
                gt[x][i]=gt[i][x]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(b[i]) AddEdge(s,i,1,0);
            else AddEdge(i,t,1,0);
        }
        for(i=1;i<=n;i++)
        {
            if(!b[i]) continue;
            for(int j=1;j<=n;j++)
            {
                if(b[j]||i==j||gt[i][j]) continue;
                AddEdge(i,j,1,girl[i]+girl[j]);
            }
        }
        Mincost(s,t);
    }
    return 0;
}
