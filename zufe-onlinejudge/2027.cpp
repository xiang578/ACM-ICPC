#include<stdio.h>
int main()
{
    int a,b,m;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        m=(a+b>a-b)?a+b:a-b;
        if(a*b>m) m=a*b;
        printf("%d\n",m);
    }
    return 0;
}
