#include<bits/stdc++.h>
using namespace std;
double dp[20000+10];
int t[1024],f,k,mx,c[1024];

int main()
{
    int n;
    while(~scanf("%d%d",&n,&f))
    {
        mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            if(c[i]>mx) mx=c[i];
            t[i]=floor((1.0+sqrt(5))*c[i]*c[i]/2.0);
        }
        //for(int i=0;i<n;i++) printf("%d\n",t[i]);
        double tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=t[i];
        }
        tmp/=n;
        for(int i=mx+1;i<=2*mx+2;i++)
            dp[i]=tmp;
        for(int i=mx;i>=f;i--)
        {
            dp[i]=0;
            for(int j=0;j<n;j++)
            {
                if(i>c[j])
                {
                   dp[i]+=t[j];
                }
                else
                {
                    dp[i]+=(1+dp[i+c[j]]);
                }
            }
            dp[i]/=n;
        }
        printf("%.3f\n",dp[f]);
    }
}
