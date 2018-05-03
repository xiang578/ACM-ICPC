#include<stdio.h>
int main()
{
    char n;
    int i;
    while (scanf(" %c",&n)!=EOF)
    {
       i=n;
    switch(i)
    {
        case 65:printf("90-100\n");break;
        case 66:printf("80-89\n");break;
        case 67:printf("70-79\n");break;
        case 68:printf("60-69\n");break;
        case 69:printf("0-59\n");break;
        default: printf("error\n");break;
    }
    }
    return 0;
}
