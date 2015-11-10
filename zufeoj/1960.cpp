#include<stdio.h>
int main()
{
    int a,c,n,i;
    while (scanf("%d",&n)!=EOF)
    {
        a=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&c);
            if(c>a) a=c;
        }
        printf("max=%d\n",a);
    }

    return 0;
}
