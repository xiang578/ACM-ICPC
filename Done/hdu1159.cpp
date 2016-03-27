#include<bits/stdc++.h>
using namespace std;

int dp[1024][1024];
int main()
{
    int i,j;
    char s1[1024],s2[1024];
    while(~scanf("%s %s",s1,s2))
    {
        memset(dp,0,sizeof(dp));
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                if(s1[i]==s2[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
