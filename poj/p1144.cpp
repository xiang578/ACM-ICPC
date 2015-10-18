#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n,g[128][128],use[128];
void dfs(int x)
{
    int i;
    use[x]=1;
    for(i=1;i<=n;i++)
    {
        if(g[x][i]&&!use[i]) dfs(i);
    }
}
int main()
{
    int i,j,u,v,ans,t;
    char st;
    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==0) break;
        memset(g,0,sizeof(g));
        while(~scanf("%d",&u))
        {
            if(u==0) break;
            for(;;)
            {
                st=getchar();
                if(st==10) break;
                scanf("%d",&v);
                g[u][v]=g[v][u]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            memset(use,0,sizeof(use));
            use[i]=1;
            t=0;
            for(j=1;j<=n;j++)
            {
                if(use[j]==1) continue;
                t++;
                dfs(j);
            }
            if(t>=2) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
