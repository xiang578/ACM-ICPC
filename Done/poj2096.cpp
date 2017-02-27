#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
double dp[1024][1024];
int n,s;

int main()
{
    while(~scanf("%d%d",&n,&s))
    {
        memset(dp,0,sizeof(dp));
        //dp[n][s]=1;
        for(int i=n;i>=0;i--)
        {
            for(int j=s;j>=0;j--)
            {
                if(i==n&&j==s) continue;
                double tmp=1;
                tmp+=(1.0*(n-i))/n*(1.0*(s-j))/s*dp[i+1][j+1];
                tmp+=(1.0*(n-i))/n*(1.0*j)/s*dp[i+1][j];
                tmp+=(1.0*i)/n*(1.0*(s-j))/s*dp[i][j+1];
                dp[i][j]=tmp/(1-(1.0*i)/n*(1.0*j)/s);
            }
        }
        printf("%.4f\n",dp[0][0]);
    }
    return 0;
}
