#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll pow3[100+5],dp[15][15],c[15][15];
int n,m;

int main()
{
    pow3[0]=1;
    for(int i=1;i<=10*10;i++)
        pow3[i]=(pow3[i-1]*3)%mod;
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<=10;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            if(i==1&&j==0) dp[1][0]=1;
            else dp[i][j]=pow3[i*j];
            for(int a=1;a<=i;a++)
            {
                for(int b=0;b<=j;b++)
                {
                    if(i==a&&j==b) continue;
                    ll tmp=c[i-1][a-1]*c[j][b]%mod;
                    tmp=(tmp*dp[a][b])%mod;
                    tmp=tmp*pow3[(i-a)*(j-b)]%mod;
                    dp[i][j]-=tmp;
                    dp[i][j]=(dp[i][j]%mod+mod)%mod;
                }
            }
        }
    }
    while(~scanf("%d%d",&n,&m))
    {
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
