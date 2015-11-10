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
const int N=1000+5;
int g[N][N],vis[N],low[N],dfn[N],sub[N],dep,n,son;

void dfs(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(g[u][v])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dep++;
                dfn[v]=low[v]=dep;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if(low[v]>=dfn[u])
                {
                    if(u==1) son++;
                    else sub[u]++;
                }
            }
            else
              low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    int i,j,u,v,flag,cas=0;
    while(~scanf("%d",&u))
    {
        n=0;
        n=max(n,u);
        if(u==0) break;
        memset(g,0,sizeof(g));
        scanf("%d",&v);
        n=max(n,v);
        g[u][v]=g[v][u]=1;
        while(~scanf("%d",&u))
        {
            if(u==0) break;
            n=max(n,u);
            scanf("%d",&v);
            n=max(n,v);
            g[u][v]=g[v][u]=1;
        }
        memset(vis,0,sizeof(vis));
        memset(sub,0,sizeof(sub));
        dep=1;
        son=0;
        dfn[1]=low[1]=vis[1]=1;
        dfs(1);
        if(son>1) sub[1]=son-1;
        flag=0;
        if(cas>0) printf("\n");
        printf("Network #%d\n",++cas);
        for(i=1;i<=n;i++)
        {
            //printf("%d\n",sub[i]);
            if(sub[i])
            {
                flag=1;
                printf("  SPF node %d leaves %d subnets\n",i,sub[i]+1);
            }
        }
        if(!flag)
            printf("  No SPF nodes\n");
    }
    return 0;
}
