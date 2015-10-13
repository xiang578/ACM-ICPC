#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,d,t;
    while (scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        d=b*b-4*a*c;
        if(d>=0)
        {
           double x1=(-b+sqrt(d))/(2*a);
           double x2=(-b-sqrt(d))/(2*a);
           if(x2>x1)
           {
               t=x2;
               x2=x1;
               x1=t;
           }
           printf("the roots are %lf and %lf\n",x1,x2);
        }
        else printf("delta is negative, no root.\n");
}
return 0;
}
