#include<stdio.h>
int main()
{
    int a,b,c,i,n;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if(a==-1&&b==-1&&c==-1) break;
        a=a%3,b=b%5,c=c%7;
        for(i=1;i<9999999;i++)
        {
            if(i%3==a&&i%5==b&&i%7==c) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
