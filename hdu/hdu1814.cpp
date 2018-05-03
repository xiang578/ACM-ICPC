#include<bits/stdc++.h>
using namespace std;
const int N=8000+10;
int n,m,c,s[2*N],mark[2*N];
vector<int>g[2*N];

void add(int x,int y)
{
    g[y].push_back(x^1);
    g[x].push_back(y^1);
}

int dfs(int x)
{
    if(mark[x^1]) return 0;
    if(mark[x]) return 1;
    mark[x]=1;
    s[c++]=x;
    for(int i=0; i<g[x].size(); i++)
    {
        if(!dfs(g[x][i]))
            return 0;
    }
    return 1;
}
int solve()
{
    for(int i=0; i<2*n; i+=2)
    {
        if(!mark[i]&&!mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0)
                    mark[s[--c]]=0;
                if(!dfs(i+1)) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<2*n; i++)
            g[i].clear();
        memset(mark,0,sizeof(mark));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            add(u,v);
        }
        if(solve()==0) puts("NIE");
        else
        {
            for(int i=0; i<2*n; i++)
            {
                if(mark[i])
                    printf("%d\n",i+1);
            }
        }
    }
    return 0;
}
