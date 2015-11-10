#include<stdio.h>
#include<math.h>
int main()
{
    double x,y;
    scanf("%lf",&x);
    if(x<0) y=fabs(x);
    else if(x>=4) y=2*x+5;
    else if(x>=2&&x<4)  y=pow(x+2,3);
    else y=sqrt(x+1);
    printf("%.2f",y);

    return 0;
}
