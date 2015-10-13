#include<stdio.h>
int main()
{
    int y,a=28;
    scanf("%d",&y);
    if((y%4==0&&y%100!=0)||y%400==0)
    a=a+1;
    printf("%d\n",a);
    return 0;
}
