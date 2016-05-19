#include<bits/stdc++.h>
using namespace std;
int n,a[1024][1024],b[1024],dp[1024],t;
int inf=0x3fffffff;
int main()
{
    while(~scanf("%d",&n))
    {
        int ans=-inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            memset(b,0,sizeof(b));
            for(int j=0;j+i<=n;j++)
            {
                for(int k=1;k<=n;k++)
                   { b[k]+=a[i+j][k];}
                t=0;
                for(int k=1;k<=n;k++)
                {
                    t+=b[k];
                    if(t>ans)
                         ans=t;
                    else
                    if(t<0)
                        t=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
