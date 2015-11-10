#include<stdio.h>
int main()
{
    int n,a[102],i;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int t=0;
        for(i=0;i<n;i++)
        {
            while(a[i]>0)
            {
                if(a[i]>=100) {t+=a[i]/100;a[i]=a[i]%100;}
                if(a[i]>=50&&a[i]<100) {t+=1;a[i]=a[i]-50;}
                if(a[i]>=10&&a[i]<50) {t+=a[i]/10;a[i]=a[i]%10;}
                if(a[i]>=5&&a[i]<10) {t+=1;a[i]=a[i]-5;}
                if(a[i]>=2&&a[i]<5) {t+=a[i]/2;a[i]=a[i]%2;}
                if(a[i]==1) {t+=1;a[i]-=1;}
            }
        }
         printf("%d\n",t);
    }
    return 0;
}
