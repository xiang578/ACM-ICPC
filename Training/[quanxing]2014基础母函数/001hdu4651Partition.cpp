#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int _max = 100000+5;
int dp[100000+5];
int main()
{

    int n;
    int i, j;
    int _;
    cin>>_;
    while(_--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                dp[j]+=dp[j-i];
                dp[j]%=mod;
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
