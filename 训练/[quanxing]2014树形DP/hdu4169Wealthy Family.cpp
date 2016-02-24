#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N=150000+10;
int n,m,w[N],dp[1024];
vector<int>v[N];

int dfs(int x)
{
    int y,i,j,k,tot=0,cnt,cur[1024];
    for(j=1; j<=m; j++)
        dp[0]=cur[j]=-inf;
    dp[0]=cur[0]=0;
    for(i=0; i<v[x].size(); i++)
    {
        y=v[x][i];
        cnt=dfs(y);
        for(j=tot; j>=0; j--)
        {
            for(k=1; k<=cnt; k++)
            {
                if(j+k>m) break;
                cur[j+k]=max(cur[j+k],dp[k]+cur[j]);
            }
        }
        tot=min(m,tot+cnt);
    }
    tot=max(tot,1);
    cur[1]=max(cur[1],w[x]);
    for(i=0; i<=m; i++) dp[i]=cur[i];
    return tot;
}

int main()
{
    int i,j,a,b,rt;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<=n; i++)
            v[i].clear();
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&a,&w[i]);
            v[a].push_back(i);
            if(a==0) rt=i;
        }
        dfs(rt);
        if(dp[m]<0)
            printf("impossible\n");
        else
            printf("%d\n",dp[m]);
    }
    return 0;
}
