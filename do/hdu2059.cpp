#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const double inf=1e8;
double s[1024];
int a[1024];

int main()
{
    double a1,a2,ans,tl,t,v,v1,v2,tmp,tc,ts;
    int i,n,m,c,j,l;
    while(~scanf("%lf",&tl))
    {
        scanf("%d%d%lf",&n,&c,&t);
        scanf("%lf%lf%lf",&v,&v1,&v2);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        l=tl*1.0;
        ans=(tl*1.0)/v;
        a[0]=0;
        a[n+1]=l;
        s[0]=0;
        for(i=1;i<=n+1;i++)
        {
            s[i]=inf;
            for(j=0;j<i;j++)
            {
                m=a[i]-a[j];
                a1=m*1.0/v2;
                if(m<=c)
                {
                    a2=1.0*m/v1;
                }
                else
                {
                        a2=1.0*c/v1+1.0*(m-c)/v2;
                }
                if(j) a2+=t;
                s[i]=min(s[i],min(a1+s[j],a2+s[j]));
            }
        }
        //printf("%lf %lf\n",s[n+1],ans);
        if(s[n+1]>ans) puts("Good job,rabbit!");
        else puts("What a pity rabbit!");
    }
    return 0;
}
