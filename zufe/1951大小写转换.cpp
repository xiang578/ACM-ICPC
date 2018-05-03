#include<stdio.h>
int main()
{
    char a[150];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        a[0]=a[0]-32;
        printf("%s\n",a);
    }
    return 0;
}
