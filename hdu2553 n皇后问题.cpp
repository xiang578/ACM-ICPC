#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,cnt,vis[3][2*N];

void dfs(int cur)
{
    if(cur==n)
    {
        cnt++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][cur-i+N])
        {
            vis[0][i]=1;
            vis[1][i+cur]=1;
            vis[2][cur-i+N]=1;
            dfs(cur+1);
            vis[0][i]=0;
            vis[1][i+cur]=0;
            vis[2][cur-i+N]=0;
        }
    }
}

int main()
{
    int ans[N],i;
    memset(ans,0,sizeof(ans));
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        if(ans[n]==0)
        {
            cnt=0;
            memset(vis,0,sizeof(vis));
            dfs(0);
            ans[n]=cnt;
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}
