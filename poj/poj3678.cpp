#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
const int N=10000;
stack<int>st;
vector<int>g[N];
int id[N],dfn[N],low[N],cnt,def,n,m;

void add(int u,int v)
{
    g[u].push_back(v);
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
        low[k]=2*n;
        st.pop();
    }
    while(k!=u);
}

void init()
{
    for(int i=0; i<2*n; i++)
    {
        g[i].clear();
        id[i]=i;
    }
    def=0;
    cnt=0;
    memset(dfn,0xff,sizeof(dfn));
    while(!st.empty()) st.pop();
}

int main()
{
    char s[10];
    int a,b,c,u0,v0,u1,v1;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%s",&a,&b,&c,s);
            u0=a*2;
            v0=b*2;
            u1=a*2+1;
            v1=b*2+1;
            if(s[0]=='A')
            {
                if(c==0)
                {
                    add(v1,u0);
                    add(u1,v0);
                }
                else
                {
                    add(v0,v1);
                    add(u0,u1);
                    add(v1,u1);
                    add(u1,v1);
                }
            }
            else if(s[0]=='O')
            {
                if(c==0)
                {
                    add(v1,v0);
                    add(u1,u0);
                    add(v0,u0);
                    add(u0,v0);
                }
                else
                {
                    add(v0,u1);
                    add(u0,v1);
                }
            }
            else if(s[0]=='X')
            {
                if(c==0)
                {
                    add(v0,u0);
                    add(u0,v0);
                    add(v1,u1);
                    add(u1,v1);
                }
                else
                {
                    add(u0,v1);
                    add(v1,u0);
                    add(v0,u1);
                    add(u1,v0);

                }
            }
        }
        for(int i=0; i<2*n; i++)
            if(dfn[i]==-1) tarjan(i);
        bool ok=1;
        for(int i=0; i<n; i++)
        {
            if(id[2*i]==id[2*i+1])
            {
                ok=0;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
