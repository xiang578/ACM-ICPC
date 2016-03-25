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

int n,p,g[400][400],mk[400],cx[400],cy[400];

int dfs(int u)
{
    int v;
    for(v=1;v<=n;v++)
    {
        if(g[u][v]&&mk[v]==0)
        {
            mk[v]=1;
            if(cy[v]==0||dfs(cy[v]))
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
    int ret=0,i;
    memset(cx,0,sizeof(cx));
    memset(cy,0,sizeof(cy));
    for(i=1;i<=p;i++)
    {
        if(cx[i]==0)
        {
            memset(mk,0,sizeof(mk));
            ret+=dfs(i);
        }
    }
    return ret;
}
int main()
{
    int  i,_,t,u,j;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&p,&n);
        memset(g,0,sizeof(g));
        for(i=1;i<=p;i++)
        {
            scanf("%d",&t);
            for(j=0;j<t;j++)
            {
                scanf("%d",&u);
                g[i][u]=1;
            }
        }
        if(MaxMatch()==p) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
