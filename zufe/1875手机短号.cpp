#include<stdio.h>
int main()
{
    int i,n,j;
    char a[11];
    while (scanf("%d",&n)!=EOF)
    {
        for(j=0;j<n;j++)
        {

            scanf("%s",a);
            printf("6");
            for(i=6;i<11;i++)
            {
                j=a[i];
                printf("%d\n",j);
            }
            printf("\n");
        }


    }
    return 0;
}
