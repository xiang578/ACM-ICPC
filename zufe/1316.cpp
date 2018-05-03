#include<stdio.h>
int main()
{
    int a,i,c,b;
    while(scanf("%d",&a)&&a)
    {
        c=0;
        for(i=1;i<=a;i++)
        {scanf("%d",&b);
        c+=b;}
    printf("%d\n",c);
    }
    return 0;
}
