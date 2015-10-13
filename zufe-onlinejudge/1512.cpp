#include<stdio.h>
int  main()
{
    int n,a[24]={1,1},i;
    for(i=2;i<24;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        printf("%d\n",a[n-1]);
    }
    return 0;
}
