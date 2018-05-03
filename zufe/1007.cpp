#include<stdio.h>
int main()
{
    double tax,r,s;
    scanf("%lf",&s);
    int d=(int(s-850))/500;
    if(d<=0) d=-1;
    if(d>10) d=10;
    switch(d)
    {
        case-1:r=0.0;break;
        case 0:r=0.05;break;
        case 1:
        case 2:
        case 3:r=0.10;break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:r=0.15;break;
        case 10:r=0.20;break;
    }
    tax=r*(s-850);
    printf("tax = %.4f\n",tax);
    return 0;
}
