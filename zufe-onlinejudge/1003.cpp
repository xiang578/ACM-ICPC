#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double c1,c2,c3,a1,a2,a3;
    double pi=2*asin(1);
    c1=(a*a+b*b-c*c)/(2*a*b);
    c2=(a*a+c*c-b*b)/(2*a*c);
    c3=(c*c+b*b-a*a)/(2*c*b);
    a1=acos(c1);
    a2=acos(c2);
    a3=acos(c3);
    a1=a1*180/pi;
    a2=a2*180/pi;
    a3=a3*180/pi;
    printf("%.4f\n",a1);
    return 0;
}
