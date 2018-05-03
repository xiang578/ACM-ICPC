#include<stdio.h>
#include<math.h>
void f1(double a,double b,double d)
{
    double x1=(-b+sqrt(d))/(2*a);
    double x2=(-b-sqrt(d))/(2*a);
    printf("x1=%.3f x2=%.3f\n",x1,x2);

}
void f2(double a,double b,double d)
{
    printf("x1=%.3f+%.3fi x2=%.3f-%.3fi\n",-b/(2*a),sqrt(-d)/(2*a),-b/(2*a),sqrt(-d)/(2*a));

}
int main()
{
    double a,b,c,d;
    while(~scanf("%lf%lf%lf",&a,&b,&c))
    {
        d=b*b-4*a*c;
        if(d>=0) f1(a,b,d);
    else f2(a,b,d);
    }
    return 0;
}
