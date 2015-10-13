#include<stdio.h>
int main()
{
    int n,a[104],i,t,s;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        t=99999999;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<t) {t=a[i];s=i;}
        }
        a[s]=a[0];
        a[0]=t;
        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
