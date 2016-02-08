#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll f[1024],c[1024][1024],ans;

int main()
{
    int n,m,i,j;
    f[0]=1;
    f[1]=1;
    for(i=2;i<=1000;i++)
        f[i]=(f[i-1]+(ll)(f[i-2]*(i-1)))%mod;
    memset(c,0,sizeof(c));
    for(i=1;i<=1000;i++)
    {
        c[i][i]=1;
        c[i][0]=1;
        for(j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    while(~scanf("%d%d",&n,&m))
    {
        ans=(f[m-1]*f[n-m])%mod;
        ans=(ans*c[n-1][n-m])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
