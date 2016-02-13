#include<bits/stdc++.h>
using namespace std;

int n,dp[2048],all[2048],p[2048],rt;
vector<int>v[2048];

void dfs(int x)
{
    int i,y,tmp=0;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        dfs(y);
        dp[x]+=all[y];
        tmp+=dp[y];
    }
    all[x]=min(dp[x],tmp);
}
int main()
{
    int i,j,a,b,m;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            v[i].clear();
            p[i]=-1;
            dp[i]=1;
            all[i]=0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d:(%d)",&a,&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&b);
                p[b]=a;
                v[a].push_back(b);
            }
        }
        rt=0;
        while(p[rt]!=-1) rt=p[rt];
        dfs(rt);
        printf("%d\n",all[rt]);
    }
    return 0;
}
