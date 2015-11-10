#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double x,y,n,w,k;
    int t;
    while(~scanf("%lf",&n))
    {
        if(n==0) break;
        scanf("%lf%lf",&w,&k);
        t=0;
        x=n;
        while(x>=w)
        {
            t++;
            x-=k*x;
        }
        printf("%d\n",t);
    }
    return 0;
}
