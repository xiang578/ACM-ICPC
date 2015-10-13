#include "stdio.h"
int main()
{
    int n,i,j;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n-i; j++) printf(" ");
            if(i==1) for(j=1; j<=n; j++) printf("*");
            else if(i==n) for(j=1; j<=3*n-2; j++) printf("*");
            else
            {
                printf("*");
                j++;
                for(j=1;j<=n+2*(i-2); j++)
                    printf(" ");
                printf("*");
            }
            for(j=1; j<=n-i; j++) printf(" ");
            printf("\n");
        }
    }
    return 0;
}
