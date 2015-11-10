#include<stdio.h>
int main()
{
    int a[100],j=0,i;
    while (scanf("%d",&a[j])!=EOF)j++;
    for (i=0;i<j;i++)
    {
        printf("%c",a[i]+1);
    }
    return 0;
}
