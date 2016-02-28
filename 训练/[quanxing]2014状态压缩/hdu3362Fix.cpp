#include<bits/stdc++.h>
using namespace std;
const double inf=999999;
double dp[1<<18+1];
struct node
{
    double x,y;
    int c;
}p[20];
double g[20][20];

double dis(double a1,double b1,double a2,double b2)
{
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

int main()
{
    int i,j,n,up,a,b;
    while(~scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].c);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(p[i].c==1&&p[j].c==1) g[i][j]=0;
                else g[i][j]=dis(p[i].x,p[i].y,p[j].x,p[j].y);
                //printf("%d %d %lf\n",i,j,g[i][j]);
            }
        }
        up=1<<n;
        for(i=0;i<up;i++)
            dp[i]=inf;
        dp[0]=0;
        for(i=0;i<up;i++)
        {
            if(dp[i]>=inf) continue;
            for(j=0;j<n;j++)
            {
                if((1<<j)&i) continue;
                if(p[j].c)
                {
                    dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]);
                }
                else
                {
                    for(a=0;a<n;a++)
                    {
                        if((i&(1<<a))==0) continue;
                        if(a==j) continue;
                        for(b=0;b<n;b++)
                        {
                            if((i&(1<<b))==0) continue;
                            if(a==b||b==j) continue;
                            //printf("%d %d %d %d\n",a,b,i,j);
                            dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+g[a][j]+g[b][j]);
                        }
                    }
                }
            }
        }
        //for(i=0;i<up;i++)   printf("%d %.6f\n",i,dp[i]);
        if(dp[up-1]<inf) printf("%.6f\n",dp[up-1]);
        else puts("No Solution");
    }
    return 0;
}
