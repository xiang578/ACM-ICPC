#include<stdio.h>
int main()
{
    int n,s,i;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=1,s=1;i<=n;i++) s=s*i;
        printf("%d! = %d\n",n,s);
    }

    return 0;
}
