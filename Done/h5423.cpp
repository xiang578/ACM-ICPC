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

vector<int>g[1024];
int n,cnt[1024],flag,vis[1024];
void dfs(int x,int sum)
{
    vis[x]=sum;
    for(int i=0;i<g[x].size();i++)
    {
        if(vis[g[x][i]]==-1)
            dfs(g[x][i],sum+1);
    }
}
int main()
{
    int i,u,v;
    while(~scanf("%d",&n))
    {
        memset(cnt,0,sizeof(cnt));
        memset(vis,0xff,sizeof(vis));
        for(i=0;i<=n;i++)
            g[i].clear();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(i=1;i<=n;i++)
            cnt[vis[i]]++;
        int t=0;
        for(i=n;i>=0;i--)
        {
            if(cnt[i])
            {
                if(t==0) t=1;
                else if(cnt[i]>1) break;
            }
        }
        if(i==-1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
