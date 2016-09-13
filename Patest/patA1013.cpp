#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int n,m,k,u[N];
vector<int>g[N];

void dfs(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(u[y]==0)
        {
            u[y]=1;
            dfs(y);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<k;i++)
    {
        int a,cnt=0;
        memset(u,0,sizeof(u));
        scanf("%d",&a);
        u[a]=1;
        for(int i=1;i<=n;i++)
        {
            if(u[i]==0) {dfs(i);cnt++;}
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}
