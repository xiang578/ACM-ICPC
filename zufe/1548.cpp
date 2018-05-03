#include<stdio.h>
int main()
{
    int i,n,s,d,f;
    double a;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        s=d=f=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a);
            if(a==0) d++;
            if(a>0) f++;
            if(a<0) s++;
        }
        printf("%d %d %d\n",s,d,f);
    }
    return 0;
}
