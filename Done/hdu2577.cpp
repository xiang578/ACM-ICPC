#include<bits/stdc++.h>
using namespace std;
struct node
{
    int n,a;
} p[1024];

char s[1024];
int dp[1024][2];

int ch(char c)
{
    if('A'<=c&&c<='Z') return 1;
    else return 0;
}

int main()
{
    int n,i,len,j,t,ans;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        len=strlen(s);
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(i=0;i<len;i++)
        {
            //uppercase
            if(ch(s[i]))
            {
                dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+1);
                dp[i+1][0]=min(dp[i][0]+2,dp[i][1]+2);
            }
            //lowercase
            else
            {
                dp[i+1][0]=min(dp[i][0]+1,dp[i][1]+2);
                dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+2);
            }
        }
        printf("%d\n",min(dp[len][1]+1,dp[len][0]));
    }
    return 0;
}
