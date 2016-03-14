#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1<<14];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n,m,k,t,w,ans;
    while(~scanf("%d%d",&n,&m))
    {
        m=1<<m;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            w=0;
            for(j=0;j<k;j++)
            {
                scanf("%d",&t);
                w+=1<<(t-1);
            }
            dp[w]=1;
            for(j=0;j<m;j++)
                if(dp[j])
                    dp[w|j]=1;
        }
        ans=0;
        for(i=0;i<m;i++)
            if(dp[i])
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}
