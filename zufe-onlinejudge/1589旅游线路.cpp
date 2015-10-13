#include<stdio.h>
int main()
{
    int n,a[50],c[50],i,j,k,t,s,h;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            a[i]=0;c[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&h);
            a[i]+=h*60;
            h=0;
            for(j=1;j<=n;j++)
                {scanf("%d",&k);c[j-1]+=k;h+=k;}
            a[i]+=h*50;
        }
        for(i=0;i<n;i++)
        {
            a[i]+=c[i]*50;
        }
        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
    }
    return 0;
}
