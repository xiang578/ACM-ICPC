/* ***********************************************
Author        :xryz
Email         :523689985@qq.com
Created Time  :2015/4/9 19:45:38
File Name     :C:\Users\Administrator\Desktop\a.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=100000+10;
int n,m,u,v,vis[N];
long long a[N],sum[N];
long long ans,all;
vector<int>g[N];

void dfs(int x)
{
    vis[x]=1;
    sum[x]=a[x];
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(vis[y]) continue;
        dfs(y);
        sum[x]+=sum[y];
    }
    //printf("%d %lld\n",x,sum[x]);
    long long tmp=all-sum[x]-sum[x];
    if(tmp<0) tmp=-tmp;
    ans=min(ans,tmp);
}

int main()
{
    int cas=0;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        all=0;
        for(int i=1;i<=n;i++)
        {
            sum[i]=0;
            g[i].clear();
            scanf("%lld",&a[i]);
            all+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=all;
        memset(vis,0,sizeof(vis));
        dfs(1);
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
