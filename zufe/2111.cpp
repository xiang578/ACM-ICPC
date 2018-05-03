#include<stdio.h>
int main()
{
    double a,b,c,d,e,t;
    while (scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e)!=EOF)
    {

       t=e/d;
       t=t*c;
       t=t-b+a;
       printf("%.4lf\n",t);
    }

 return 0;
}
