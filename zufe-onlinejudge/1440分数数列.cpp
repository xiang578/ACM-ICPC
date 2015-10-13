#include<stdio.h>
int main()
{
    double a,b,s,n,i;
    while (~scanf("%lf",&n))
    {
        s=0;b=1;a=2;
        for(i=0;i<n;i++)
        {
            s+=a/b;
            a=a+b;
            b=a-b;
        }
        printf("%.2f\n",s);
    }
    return 0;
}
