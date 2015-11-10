#include<stdio.h>
int main()
{
    double a,b,c,d,e,t;
    while (scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e)!=EOF)
    {
       t=a+b-c;
       t=t*d;
       t=t/e;
       printf("%.4lf\n",t);
    }

 return 0;
}
