#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
vector<int>g[20000+10];
int son[20000+10],n,a,b,ans,mi;

void dfs(int x,int fa)
{
    int tmp=0;
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]==fa)  continue;
        dfs(g[x][i],x);
        son[x]+=son[g[x][i]]+1;
        tmp=max(tmp,son[g[x][i]]+1);
    }
    tmp=max(tmp,n-son[x]-1);
    if(tmp<mi||(tmp==mi&&x<ans))
    {
        mi=tmp;
        ans=x;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(son,0,sizeof(son));
        mi=n;
        dfs(1,0);
        printf("%d %d\n",ans,mi);
    }
    return 0;
}
