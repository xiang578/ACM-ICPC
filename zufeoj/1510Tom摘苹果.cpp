#include<stdio.h>
int main()
{
    int a[11],b,i,s=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&b);
    b+=30;
    for(i=0;i<10;i++)
    {
        if(a[i]<=b) s++;
    }
    printf("%d\n",s);
    return 0;
}
