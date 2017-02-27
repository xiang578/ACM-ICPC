#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
double dp[N];
int t[N],n,m;

int main()
{
    while(cin>>n>>m)
    {
        if(!n&&!m) break;
        memset(t,0,sizeof(t));
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            t[a]=b;
        }
        for(int i=0; i<=6; i++) dp[n+i]=0;
        for(int i=n-1; i>=0; i--)
        {
            if(t[i])
            {
                dp[i]=dp[t[i]];
            }
            else
            {
                dp[i]=1;
                for(int j=1; j<=6; j++)
                {
                    dp[i]+=dp[i+j]/6;
                }
            }
        }
        printf("%.4f\n",dp[0]);
    }
    return 0;
}
