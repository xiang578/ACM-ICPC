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
        printf("Fibonacci�����У���һ������%d�����ǵ�%d��������ֵΪ%d\n",n,s,b);
        printf("Fibonacci�����У�������%d��������ǵ�%d��������ֵΪ%d\n",n,s-1,a);
    }
    return 0;
}
