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

int nx,ny,g[128][128],cx[128],cy[128],mk[128];
int dfs(int u)
{
    for(int v=1;v<=ny;v++)
    {
        if(!mk[v]&&g[u][v])
        {
            mk[v]=1;
            if(cy[v]==-1||dfs(cy[v]))
            {
                cx[u]=v;
                cy[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int ret=0;
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    for(int i=1;i<=nx;i++)
    {
        if(cx[i]==-1)
        {
            memset(mk,0,sizeof(mk));
            ret+=dfs(i);
        }
    }
    return ret;
}
int main()
{
    int i,j,u,v,w,k;
    while(~scanf("%d",&nx))
    {
        if(nx==0) break;
        scanf("%d%d",&ny,&k);
        memset(g,0,sizeof(g));
        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&w,&u,&v);
            g[u][v]=1;
        }
        printf("%d\n",MaxMatch());
    }
    return 0;
}
