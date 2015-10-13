#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    double a,b,c;
    while(~scanf("%lf%lf%lf",&a,&b,&c))
    {
        if(b*b-4*a*c>0) t=2;
        else if(b*b-4*a*c==0) t=1;
        else t=0;
        printf("%d\n",t);
    }
    return 0;
}
