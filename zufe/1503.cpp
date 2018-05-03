#include<stdio.h>
int main()
{
    int n,i,j;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++) printf(" ");
            for(j=1;j<=2*i-1;j++) printf("%d",i);
            printf("\n");
        }
        for(j=1;j<=n-1;j++) printf(" ");
        printf("0\n");
     printf("\n");
    }
    return 0;
}
