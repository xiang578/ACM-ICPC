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

int n,p[1024],g[1024][1024],cx[1024],cy[1024],my[1024];

int dfs(int u)
{
    int v;
    for(v=0;v<n;v++)
    {
        if(g[u][v]==1&&my[v]==0)
        {
            my[v]=1;
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
    int i,res=0;
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    for(i=0;i<n;i++)
    {
        if(cx[i]==-1)
        {
            memset(my,0,sizeof(my));
            res+=dfs(i);
        }
    }
    return res;
}

int main()
{
    int i,j,t,m;
    while(~scanf("%d",&n))
    {
        memset(p,0xff,sizeof(p));
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            scanf("%d: (%d)",&t,&m);
            if(m==0) continue;
            for(j=0;j<m;j++)
            {
                scanf("%d",&t);
                g[t][i]=g[i][t]=1;
            }
        }
        int ans=MaxMatch();
        if(ans%2==1) ans++;
        printf("%d\n",n-ans/2);
    }
    return 0;
}
