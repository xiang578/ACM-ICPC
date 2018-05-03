#include<stdio.h>
int  main()
{
    int n,s,i,a[9],t;
    while(~scanf("%d",&t))
    {
        if(t==0) break;
        while(t--){
       for(i=0;i<7;i++)
        {
            scanf("%d",&a[i]);
        }
       s=a[0]+a[1]+a[2]+a[6]-a[3]-a[4]-a[5];
        printf("%d\n",s);
    }
}
    return 0;
}
