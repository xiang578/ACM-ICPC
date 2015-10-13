#include<stdio.h>
int main ()
{
    int i,s=0;
    for(i=100;i<=1000;i++)
    {
        if(i%2==0&&i%3==0) s+=i;
    }
    printf("sum = %d",s);
    return 0;
}
