#include<stdio.h>
int main()
{
    int n,j,i;
    char c;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++) printf(" ");
            for(j=1;j<=i;j++)
            {
                c='A';c+=j-1;
                printf("%c",c);
            }
            for (j=1;j<=i;j++)
            {
                c='Z';c-=i-j;
                printf("%c",c);
            }
            printf("\n");
        }
    }
    return 0;
}
