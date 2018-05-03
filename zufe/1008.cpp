#include<stdio.h>
#include<math.h>
int main ()
{
    double l1,l2,l3;
    while(scanf("%lf%lf%lf",&l1,&l2,&l3)!=EOF)
    {
        double cos1=(l2*l2+l3*l3-l1*l1)/(2*l2*l3);
        double sin1=sqrt(1-cos1*cos1);
        double r=0.5*l1/sin1;
        printf("%.2f\n",2*asin(1)*r*r);
    }
    return 0;
}
