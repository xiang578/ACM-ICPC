#include<stdio.h>
int main()
{
    int a,b;
    int n,s;
    while(scanf("%d",&n)!=EOF)
    {
        a=1,b=1,s=2;
        while (b<=n)
        {
            b=a+b;a=b-a;
            s++;
        }
        printf("Fibonacci数列中，第一个大于%d的数是第%d个数，其值为%d\n",n,s,b);
        printf("Fibonacci数列中，不大于%d的最大数是第%d个数，其值为%d\n",n,s-1,a);
    }
    return 0;
}
