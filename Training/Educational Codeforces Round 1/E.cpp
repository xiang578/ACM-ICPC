#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
int dp[35][35][55];

int dfs(int n,int m,int k)
{
    int ans=inf;
    if(k>n*m) return dp[n][m][k]=inf;
    if(k==n*m||k==0) return dp[n][m][k]=0;
    if(dp[n][m][k]!=-1) return dp[n][m][k];
    int i,j;
    for(i=1;i<n;i++)
        for(j=0;j<=k;j++)
            ans=min(ans,dfs(i,m,j)+dfs(n-i,m,k-j)+m*m);
    for(i=1;i<m;i++)
        for(j=0;j<=k;j++)
            ans=min(ans,dfs(n,i,j)+dfs(n,m-i,k-j)+n*n);
    //printf("%d %d %d %d\n",n,m,k,ans);
    return dp[n][m][k]=ans;
}

int main()
{
    int _,n,m,k;
    scanf("%d",&_);
    memset(dp,0xff,sizeof(dp));
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",dfs(n,m,k));
    }
    return 0;
}
