#include<stdio.h>
int main ()
{
    int n;
    int i,j;
    while (scanf("%d",&n)!=EOF)
    {
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*n-2*i;j++) printf(" ");
        for(j=1;j<=4*i-3;j++) printf("*");
        printf("\n");

    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=2*i;j++) printf(" ");
        for(j=1;j<=4*n-3-4*i;j++) printf("*");
        printf("\n");

    }
    }
    return 0;
}
