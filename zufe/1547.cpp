#include<stdio.h>
int  main()
{
    int n,s,i,a;
    while(~scanf("%d",&n))
    {
        s=1;
       for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a%2==0) s*=a;
        }
        printf("%d\n",s);
    }
    return 0;
}
