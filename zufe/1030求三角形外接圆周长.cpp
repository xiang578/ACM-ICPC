#include<stdio.h>
#include<math.h>
double f(double a,double b,double c,double d)
{
    double s;
    s=sqrt((a-c)*(a-c)+(b-d)*(b-d));
    return s;
}
int main()
{
    double x1,y1,x2,y2,x3,y3,t;
    double p=3.141592653589793,s,a,b,c;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        a=f(x1,y1,x2,y2);
        b=f(x2,y2,x3,y3);
        c=f(x3,y3,x1,y1);
        t=sqrt((a+b+c)*(a-b+c)*(-a+b+c)*(a+b-c));
        s=2*a*b*c/t*p;
        printf("%.2f\n",s);
    }
    return 0;
}
