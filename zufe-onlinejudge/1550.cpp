#include<stdio.h>
int  main()
{
    int n,s,i,a,t,m;
    while(~scanf("%d%d",&n,&m))
    {
        t=s=0;
       for(i=n;i<=m;i++)
        {
            if(i%2==1) s+=i*i*i;
            if(i%2==0) t+=i*i;
        }
        printf("%d %d\n",t,s);
    }
    return 0;
}
