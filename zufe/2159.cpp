#include<stdio.h>
#include<math.h>
int main()
{
    double x,y,m,z=2.0;
    scanf("%d",&x);
    m=pow(x+1,z);
    if(x>=0) y=sqrt(x);
    else y=1.0/x+2*x+m;
    printf("%.2f\n",y);
    return 0;
}
