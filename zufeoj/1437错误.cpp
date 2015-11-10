#include<stdio.h>
int main()
{
    double s=0;
    double a,b,c,i;
    scanf("%lf%lf%Lf",&a,&b,&c);
    for(i=1;i<=a;i++)
        {
            s+=i;
        }
    for(i=1;i<=b;i++)
    {
        s+=i*i;
    }
    for(i=1;i<=c;i++)
    {
        s+=1.0/i;
    }
    printf("%.2f",s);
    return 0;
}
