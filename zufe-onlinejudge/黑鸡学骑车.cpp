#include<stdio.h>
int main()
{
    int t;
    double a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&a,&b);
        printf("%.2f\n",a*b*3.6);
    }
    return 0;
}
