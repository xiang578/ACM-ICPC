#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1024;
const int inf=1<<24;

struct Edge
{
    int from,to,cap,flow;
};
vector<Edge>edges;
vector<int>G[N];
vector<int>gg[N];
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

int p[N];
ll ti[N];
int pr[N];
ll cost[N];

int main()
{
    int n,m,u,v,c,_,cas=0,w,ans2,ss;
    ll ans1;
    ll l,r;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0; i<N; i++)
            gg[i].clear();
        l=0;
        r=0;
        s=0;
        ss=0;
        t=n+m+1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%lld",&p[i],&ti[i]);
            r=max(ti[i],r);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&pr[i]);
            ss+=pr[i];
            int k,tmp;
            scanf("%d",&k);
            cost[i]=0;
            for(int j=0;j<k;j++)
            {
                scanf("%d",&tmp);
                gg[i].push_back(tmp);
                cost[i]=max(ti[tmp],cost[i]);
            }
        }
        ans1=-1;
        while(l<=r)
        {
            ll mid=(r+l)/2;
            edges.clear();
            for(int i=0;i<N;i++) G[i].clear();
            ss=0;
            for(int i=1;i<=m;i++)
            {
                if(cost[i]>mid) continue;
                ss+=pr[i];
                AddEdge(s,i,pr[i]);
                for(int k=0;k<gg[i].size();k++)
                {
                    AddEdge(i,gg[i][k]+m,inf);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(ti[i]>mid) continue;
                AddEdge(i+m,t,p[i]);
            }
            int tmp=Maxflow(s,t);
            if(ss-tmp>=w)
            {
                ans1=mid;
                ans2=ss-tmp;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("Case #%d: ",++cas);
        if(ans1!=-1) printf("%lld %d\n",ans1,ans2);
        else printf("impossible\n");
    }
    return 0;
}
