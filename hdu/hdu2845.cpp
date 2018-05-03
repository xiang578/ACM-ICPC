#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,dp[200000+10],b[200000+10];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        b[0]=0;
        for(int i=1;i<=n;i++)
        {
            b[i]=0;
            dp[0]=0;
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&a);
                if(j-2>=0) dp[j]=max(dp[j-1],dp[j-2]+a);
                else dp[j]=max(dp[j-1],a);
            }
            b[i]=dp[m];
            if(i-2>=0) b[i]=max(b[i-1],b[i-2]+b[i]);
            else b[i]=max(b[i-1],b[i]);
        }
        printf("%lld\n",b[n]);
    }
    return 0;
}
