#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int n,m;
double dp[N][N],r[N][N],d[N][N],p[N][N];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%lf %lf %lf",&p[i][j],&r[i][j],&d[i][j]);
                //cin>>p[i][j];
                //cin>>r[i][j];
                //cin>>d[i][j];
            }
        }
        dp[n][m]=0;
        //memset(dp,0,sizeof(dp));
        for(int i=n;i>=1;i--)
        {
            for(int j=m;j>=1;j--)
            {
                if(i==n&&j==m) continue;
                if(fabs(p[i][j]-1.00)<1e-8)
					continue;
                double tmp=r[i][j]*dp[i][j+1]+d[i][j]*dp[i+1][j]+2;
                dp[i][j]=tmp/(1-p[i][j]);
                //printf("%d %d %lf %lf\n",i,j,tmp,dp[i][j]);
            }
        }
        //for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%.3f ",dp[i][j]);
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}
