#include<stdio.h>
int main()
{
    int y,x,a=28,d=28;
    scanf("%d%d",&y,&x);
    if((y%4==0&&y%100!=0)||y%400==0)
        d=d+1;
    if((x%4==0&&x%100!=0)||x%400==0)
        a=a+1;

    printf("%d %d\n",d,a);
    return 0;
}
