#include<bits/stdc++.h>
using namespace std;
char a[1024],b[1024];
int dp[1024][1024][20],ans[1024][1024][20];

int main()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    scanf("%s",a+1);
    scanf("%s",b+1);
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    for(int k=1;k<=p;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                {
                    dp[i][j][k]=max(dp[i-1][j-1][k]+1,ans[i-1][j-1][k-1]+1);
                }
                else
                    dp[i][j][k]=0;
                ans[i][j][k]=max(ans[i-1][j][k],ans[i][j-1][k]);
                ans[i][j][k]=max(ans[i][j][k],dp[i][j][k]);
            }
        }
    }
    printf("%d\n",ans[n][m][p]);
    return 0;
}
