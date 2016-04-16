//poj 1273
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=30000;
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
struct node
{
    int up,num,id;
} p[N];

int cmp(node a,node b)
{
    return a.up<b.up;
}

int main()
{
    int n,b,u,v,c,q,m[10];
    while(~scanf("%d%d%d",&n,&b,&q))
    {
        edges.clear();
        for(int i=0; i<N; i++) G[i].clear();
        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&p[i].up,&p[i].num);
        }
        p[q].up=b;
        p[q].num=n;
        q++;
        s=0;
        t=q+5+1;
        sort(p,p+q,cmp);
        for(int i=0; i<5; i++)
        {
            m[i]=q+i+1;
            AddEdge(s,m[i],n/5);
        }
        for(int i=0; i<q; i++)
        {
            p[i].id=i+1;
             if(p[i].num>p[i+1].num&&i+1<q)
            {
                puts("unfair");
                return 0;
            }
        }

        AddEdge(p[0].id,t,p[0].num);
        for(int j=0;j<5;j++)
        {
            int n2=p[0].up/5;
            if(p[0].up%5>j) n2++;
            AddEdge(m[j],p[0].id,n2);
        }

        for(int i=1;i<q;i++)
        {
            AddEdge(p[i].id,t,p[i].num-p[i-1].num);
            //printf("%d %d %d\n",p[i].id,t,p[i].num);
            for(int j=0;j<5;j++)
            {
                int n1=p[i-1].up/5;
                int n2=p[i].up/5;
                if(p[i-1].up%5>j) n1++;
                if(p[i].up%5>j) n2++;
                AddEdge(m[j],p[i].id,n2-n1);
            }
        }
        //printf("%d\n",Maxflow(s,t));
        if(Maxflow(s,t)==n) puts("fair");
        else puts("unfair");
    }
    return 0;
}
