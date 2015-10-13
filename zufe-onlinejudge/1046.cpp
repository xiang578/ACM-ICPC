#include<stdio.h>
double ctof(double c)
{
    double f;
    f=32+c*9/5;
    return f;
}
int main()
{
    double c,f;
    int i;
    for(i=-100;i<=150;i+=5)
    {   c=i;
        f=ctof(c);
        printf("c=%.f->f=%.f\n",c,f);

    }
 return 0;
}
