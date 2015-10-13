#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a)
        {
        if((a%4==0&&a%100!=0)||a%400==0)
            printf("29\n");
        else
            printf("28\n");
        }
        else break ;
    }
    return 0;
}
