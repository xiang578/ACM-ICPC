#include<bits/stdc++.h>
using namespace std;
double q;
int m,a[100],dp[40000000];

int main()
{
    int i,j,n,k,f;
    double t,tmp,ta,tb,tc;
    char c;
    while(~scanf("%lf%d",&q,&n)&&n)
    {
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%*c",&k);
            ta=tb=tc=tmp=0;f=1;
            for(j=0;j<k;j++)
            {
                scanf("%c:%lf%*c",&c,&t);
                if(c=='A'||c=='B'||c=='C')
                {
                    if(t<=600)
                    {
                        tmp+=t;
                    }
                    else f=0;
                    if(c=='A') ta+=t;
                    else if(c=='B') tb+=t;
                    else if(c=='C') tc+=t;
                }
                else f=0;
            }

            if(tmp<=1000&&f&&ta<=600&&tb<=600&&tc<=600)
            {
                a[m++]=(int)(tmp*100);
            }
        }
        int s=(int)(q*100);
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++)
        {
            for(j=s;j>=a[i];j--)
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
        printf("%.2f\n",1.0*dp[s]/100);
    }
    return 0;
}
