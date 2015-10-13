#include<stdio.h>
int main()
{
    int i,n,a[106],b,m,t;
    while(~scanf("%d",&n))
    {
        t=0;
        m=-1;
        for(i=0;i<105;i++) a[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b);
            a[b]++;
            if(b>m) m=b;
        }
        t=m*6+m*4;
        for(i=0;i<=m;i++)
        {
            if(a[i]>0) t=t+5+a[i];
        }
        printf("%d\n",t);
    }
    return 0;
}
