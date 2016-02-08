#include<bits/stdc++.h>
using namespace std;
const int mod=5201314;
char s[505][505];
int dp[2][505][505];

int main()
{
    int _,n,i,j,k,now,a1,b1,a2,b2,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        memset(dp,0,sizeof(dp));
        now=0;
        if(s[1][1]==s[n][n]) dp[0][1][n]=1;
        for(k=1;k<n;k++)
        {
            memset(dp[!now],0,sizeof(dp[!now]));
            now=!now;
            for(a1=1;a1<=k+1;a1++)
            {
                for(a2=n;a2>=n-k;a2--)
                {
                    b1=k+2-a1;
                    b2=2*n-k-a2;
                    if(s[a1][b1]!=s[a2][b2]) continue;
                    dp[now][a1][a2]+=dp[!now][a1-1][a2+1]+dp[!now][a1][a2+1]+dp[!now][a1-1][a2]+dp[!now][a1][a2];
                    dp[now][a1][a2]%=mod;
                }
            }
        }

        ans=0;
        for(i=1;i<=n;i++)
        {
            ans+=dp[now][i][i];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
