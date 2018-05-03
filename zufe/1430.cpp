#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n=n/10;
    if (n<5) n=5;
    switch(n)
    {
        case 10:
        case 9: printf("A\n");break;
        case 8: printf("B\n");break;
        case 7: printf("C\n");break;
        case 6: printf("D\n");break;
        case 5: printf("E\n");break;
        default :printf("error\n");break;
    }
    return 0;
}
