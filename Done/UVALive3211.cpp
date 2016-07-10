#include<bits/stdc++.h>
using namespace std;
vector<int>g[4096];
int t[2048][2],mark[4096],s[4096],c,n;

void init()
{
    memset(mark,0,sizeof(mark));
    for(int i=0;i<2*n;i++)
        g[i].clear();
}
int dfs(int x)
{
    if(mark[x^1]) return 0;
    if(mark[x]) return 1;
    mark[x]=1;
    s[c++]=x;
    for(int i=0;i<g[x].size();i++)
        if(!dfs(g[x][i]))
            return 0;
    return 1;
}
void addedge(int x,int xv,int y,int yv)
{
    x=x*2+xv;
    y=y*2+yv;
    g[x^1].push_back(y);
    g[y^1].push_back(x);
}

int solve()
{
    for(int i=0;i<2*n;i+=2)
    {
        if(!mark[i]&&!mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[s[--c]]=0;
                if(!dfs(i+1)) return 0;
            }
        }
    }
    return 1;
}

int get(int k)
{
    init();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int a=0;a<2;a++)
            {
                for(int b=0;b<2;b++)
                {
                    if(abs(t[i][a]-t[j][b])<k)
                        addedge(i,a,j,b);
                }
            }
        }
    }
    return solve();
}
int main()
{
    while(~scanf("%d",&n))
    {
        int ans,L=0,R=0,M;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                scanf("%d",&t[i][j]);
                R=max(t[i][j],R);
            }
        }

        while(L<R)
        {
            M=L+(R-L+1)/2;
            if(get(M)==1)
            {
                ans=M;
                L=M;
            }
            else
            {
                R=M-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
