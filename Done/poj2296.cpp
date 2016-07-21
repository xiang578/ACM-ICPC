#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5000;
const int B=2;
const int W=1;
stack<int>st;
vector<int>g[N];
vector<int>gt[N];
int col[N],in[N],id[N],dfn[N],low[N],cnt,def,opp[N],n;
double xx[N],yy[N];
vector<int>gg[N];
struct node
{
    double left,right,up,down;
}p[N];

void add(int u,int v)
{
    g[u].push_back(v);
}

void add2(int u,int v)
{
    gt[u].push_back(v);
}

void topsort()
{
    int u,v;
    queue<int>q;
    memset(col,0,sizeof(col));
    for(int i=1; i<=cnt; i++)
        if(!in[i]) q.push(i);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(col[u]) continue;
        col[u]=W;
        col[opp[u]]=B;
        for(int i=0; i<gt[u].size(); i++)
        {
            v=gt[u][i];
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}

void tarjan(int u)
{
    int k,mx=dfn[u]=low[u]=++def;
    st.push(u);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(dfn[v]==-1) tarjan(v);
        if(low[v]<mx) mx=low[v];
    }
    if(mx<low[u])
    {
        low[u]=mx;
        return ;
    }
    cnt++;
    do
    {
        k=st.top();
        id[k]=cnt;
        low[k]=4*n;
        st.pop();
    }
    while(k!=u);
}

void init()
{
    for(int i=0; i<4*n; i++)
    {
        g[i].clear();
        gt[i].clear();
        id[i]=i;
        in[i]=0;
    }
    def=0;
    cnt=0;
    memset(dfn,0xff,sizeof(dfn));
    while(!st.empty()) st.pop();
}
int ok(int x,int y)
{
    if(p[x].right<=p[y].left||p[y].right<=p[x].left) return 1;
    if(p[x].up<=p[y].down||p[y].up<=p[x].down) return 1;
    return 0;
}
int solve(int x)
{
    init();
    double R=x;
    for(int i=0;i<n;i++)
    {
        p[i*2].left=xx[i]-R/2;
        p[i*2].right=xx[i]+R/2;
        p[i*2].up=yy[i]+R;
        p[i*2].down=yy[i];

        p[i*2+1].left=xx[i]-R/2;
        p[i*2+1].right=xx[i]+R/2;
        p[i*2+1].up=yy[i];
        p[i*2+1].down=yy[i]-R;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ok(i*2,j*2)==0)
            {
                add(i*2,j*2+1);
                add(j*2,i*2+1);
            }

            if(ok(i*2+1,j*2+1)==0)
            {
                add(i*2+1,j*2);
                add(j*2+1,i*2);
            }

            if(ok(i*2+1,j*2)==0)
            {
                add(i*2+1,j*2+1);
                add(j*2,i*2+1);
            }

            if(ok(i*2,j*2+1)==0)
            {
                add(i*2,j*2);
                add(j*2+1,i*2+1);
            }
        }
    }
    for(int i=0; i<4*n; i++)
        if(dfn[i]==-1) tarjan(i);
    bool ok=1;
    for(int i=0; i<2*n; i++)
    {
        if(id[i*2]==id[i*2+1])
        {
            ok=0;
            break;
        }
    }
    if(!ok)
        return 0;
    else
        return 1;
}

int main()
{
    int _,L,R,M,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&xx[i],&yy[i]);
        }
        L=0;
        R=20000;
        ans=0;
        while(L<=R)
        {
            M=(L+R)/2;
            if(solve(M)==1)
            {
                ans=M;
                L=M+1;
            }
            else
                R=M-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
