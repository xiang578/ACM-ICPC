#include<stdio.h>
int main()
{
    int t,a,b,i;
    while(~scanf("%d%d",&a,&b))
    {
        a=a%10;
        t=a;
        for(i=1;i<b;i++)
        {
            a=a*t;
            a=a%10;
        }
        printf("%d\n",a);
    }
    return 0;
}
