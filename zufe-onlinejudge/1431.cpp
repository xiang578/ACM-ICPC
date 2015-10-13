#include<stdio.h>
int main()
{
    char a[10];
    int j,i,t;
    while(~scanf("%s%*c",a))
    {
        for(i=0;a[i]!='\0';i++);
        printf("%d\n",i);
        for(j=0;j<i-1;j++)
        {
          printf("%c ",a[j]);
        }
        printf("%c\n",a[i-1]);
        for(;i>=1;i--)
        printf("%c",a[i-1]);
         printf("\n");
    }
    return 0;
}
