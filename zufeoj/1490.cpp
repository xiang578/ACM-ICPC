#include<stdio.h>
int main ()
{
    int d,n;
    int i,j,a;
    scanf("%d",&d);
    for (a=0;a<d;a++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
    {

        for(j=1;j<=n-i;j++) printf(" ");
        for(j=1;j<=2*i-1;j++) printf("*");
        printf("\n");
    }
    printf("\n");
    }
    return 0;
}
