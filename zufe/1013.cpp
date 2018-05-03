#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if((a%4==0&&a%100!=0)||a%400==0)
            printf("%d is a leap year.\n",a);
        else
            printf("%d is not a leap year.\n",a);
    }
    return 0;
}
