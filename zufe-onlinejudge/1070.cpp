#include<stdio.h>
int main()
{
    double x,y;
    scanf("%lf",&x);
    if(x>10) y=3*x-11;
    else if(x<1) y=x;
    else y=2*x-1;
    printf("%.2f\n",y);
   return 0;
}
