#include<stdio.h>
double f(double a,double b)
{
    double i,s=1;
    for(i=a;i<=b;i++)
    {
        s*=i;
    }
    return s;
}
int main()
{
    double n,a,b;
    while(~scanf("%lf",&n))
    {
        n=n-2;
        a=2*f(n-2,n)/6;
        b=f(n-1,n)/2;
        printf("%.0f\n",a+b);
    }
    return 0;
}
