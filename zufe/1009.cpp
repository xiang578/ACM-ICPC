#include<stdio.h>
#include<math.h>
int main ()
{
    double r=2.7,h=3.5,v;
    double pi=2*asin(1);
    v=pi*r*r*h;
    printf("%.2f\n",v);
    return 0;
}
