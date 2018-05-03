#include<stdio.h>
#include<math.h>
int main ()
{
    double x,y;
    scanf("%lf",&x);
    if(x<0) y=x*x;
    else if(x<9) y=sqrt(x);
    else y=x-6;
    printf("%lf",y);
    return 0;
}
