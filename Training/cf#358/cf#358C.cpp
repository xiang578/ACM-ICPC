#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
struct node
{
    int to,w;
}t;
int n,a[N],u[N];
vector<node>g[N];

void dfs(int x,int w)
{
    u[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i].to;
        int tw=max(g[x][i].w,w+g[x][i].w);
        if(tw<=a[y])
            dfs(y,tw);
    }
}

int main()
{
    int fa,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        g[i].clear();
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    memset(u,0,sizeof(u));
    for(int i=2;i<=n;i++)
    {
        scanf("%d%d",&fa,&w);
        t.to=i;
        t.w=w;
        g[fa].push_back(t);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=u[i];
        //if(u[i]==1) printf("%d\n",i);
    }
    printf("%d\n",n-ans);
    return 0;
}
