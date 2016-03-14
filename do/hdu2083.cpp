#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1024],sum[1024],ans,i,_,n,tmp,t;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        ans=a[1];
        tmp=sum[n]-a[1]*n;
        for(i=2;i<=n;i++)
        {
            t=sum[n]-sum[i]-(n-i)*a[i]+i*a[i]-sum[i];
            if(tmp>t)
            {
                ans=a[i];
                tmp=t;
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}
