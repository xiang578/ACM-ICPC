#include<stdio.h>
int main()
{
    int a;
    char d;
    while(~scanf("%c%d\n",&d,&a))
    {
        d=a-d;
        printf("%c\n",d);
        printf("\n");
    }
    return 0;
}
