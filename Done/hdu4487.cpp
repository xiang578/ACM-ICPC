#include<bits/stdc++.h>
using namespace std;
double dp[2][305][305];
int main()
{
    double l,r,p,ans;
    int _,k,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&k);
        scanf("%d %lf %lf",&n,&l,&r);
        p=1-l-r;
        memset(dp,0,sizeof(dp));
        int t=0;
        dp[0][200][200]=1.0;

        for(int i=0; i<n; i++)
        {
            //printf("%.4f\n",dp[t][200][200]);
            for(int a=200-n; a<=200+n; a++)
            {
                for(int b=200-n; b<=200+n; b++)
                {
                    //printf("%d %d %lf\n",a-200,b-200,dp[t][a][b]);
                    dp[t^1][a][b]+=dp[t][a][b]*p;

                    dp[t^1][a-1][b]+=dp[t][a][b]*l;

                    if(a+1>b) dp[t^1][a+1][a+1]+=dp[t][a][b]*r;
                    else dp[t^1][a+1][b]+=dp[t][a][b]*r;
                    dp[t][a][b]=0;
                }
            }
            t=t^1;
        }
        ans=0;
        for(int a=200-n; a<=200+n; a++)
        {
            for(int b=200-n; b<=200+n; b++)
            {
               ans+=dp[t][a][b]*(b-200);

            }
        }
        printf("%d %.4f\n",k,ans);
    }
    return 0;
}
