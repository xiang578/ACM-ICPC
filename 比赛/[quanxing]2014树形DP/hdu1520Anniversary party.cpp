#include<bits/stdc++.h>
using namespace std;

int n,dp[6000+10][2],ans,p[6000+10];
vector<int>v[6000+10];

void dfs(int x)
{
    int y;
    for(int i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        dfs(y);
        dp[x][0]+=max(dp[y][0],dp[y][1]);
        dp[x][1]+=dp[y][0];
    }
    return ;
}

int main()
{
    int l,k,rt;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++)
            v[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&dp[i][1]);
        memset(p,0,sizeof(p));
        while(~scanf("%d%d",&l,&k))
        {
            if(l==0&&k==0) break;
            rt=k;
            p[l]=k;
            v[k].push_back(l);
        }
        while(p[rt]) rt=p[rt];
        dfs(rt);
        printf("%d\n",max(dp[rt][0],dp[rt][1]));
    }
    return 0;
}
