#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int dp[200][200],n,i,j,k,ans[200];
    char a[200],b[200];
    while(~scanf("%s",a))
    {
        scanf("%s",b);
        n=strlen(b);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                dp[i][j]=j-i+1;

        for(i=n-1;i>=0;i--)
        {
            for(j=i+1;j<n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(k=i+1; k<=j; k++)
                {
                    if(b[i]==b[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                }
            }
        }

        for(i=0; i<n; i++)
            ans[i]=dp[0][i];

        for(i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(i==0)
                    ans[i]=0;
                else
                    ans[i]=ans[i-1];
            }
            else
            {
                for(j=0;j<i;j++)
                    ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
            }
        }

        printf("%d\n",ans[n-1]);
    }
    return 0;
}
