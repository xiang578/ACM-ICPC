#include<stdio.h>
int main ()
{
    double  a=2,b=1,s=0.0,c;
    int i;
    for(i=0;i<20;i++)
    {
        s+=1.0*a/b;
        c=a+b;
        b=a;
        a=c;
    }
    printf("sum=%lf",s);
    return 0;

}
