/*
反例
5 5 4
1 2 8
2 3 7
3 5 7
2 4 2
4 5 2
输出 7
正确 8
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1024;
const int inf=1<<24;
const double eps=1e-10;

struct Edge
{
    int from,to,cap,flow;
};
vector<Edge>edges;
vector<int>G[N];
vector<double>ans;

int s,t,n;
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
            if(e.to==n)
            {
                ans.push_back((double)(f));
            }
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}

double Maxflow(int st,int ed,int x)
{
    int flow=0,cnt;
    double tmp,l=0,r=0,mid,out;
    ans.clear();
    while(BFS())
    {
        memset(cur,0,sizeof(cur));
        DFS(st,inf);
        //tmp=(double)
        //r=max(r,tmp);
        //ans.push_back(tmp);
    }
    for(int i=0;i<ans.size();i++)
    {
        //cout<<ans[i]<<endl;
        r=max(r,ans[i]);
    }
    //printf("%lf %lf",l,r);
    while(fabs(l-r)>eps)
    {
        //printf("%lf %lf",l,r);
        mid=(l+r)/2;
        cnt=0;
        for(int i=0;i<ans.size();i++)
        {
            cnt+=(int)(ans[i]/mid);
        }
        if(cnt>=x)
        {
            l=mid;
            out=mid;
        }
        else
        {
            r=mid;
        }
    }
    return out*x;
}

int main()
{
    int m,u,v,c,x;
    while(~scanf("%d%d%d",&n,&m,&x))
    {
         edges.clear();
        for(int i=0; i<N; i++) G[i].clear();
        s=1;t=n;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        printf("%.10f\n",Maxflow(s,t,x));
    }
    return 0;
}
