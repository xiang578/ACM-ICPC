#include<stdio.h>
float f(int n)
{
    int i;
    float j=1,s=0;
    for(i=1;i<=n;i++)
    {
        j=j*1.0/i;
        s+=j;
    }
    return s;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        printf("%.4f",f(n));
    }
    return 0;
}
