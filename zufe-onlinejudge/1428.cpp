#include<stdio.h>
int main()
{
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    t=(a>b)?a:b;
    if(c>t) t=c;
    printf("%d\n",t);
    return 0;
}
