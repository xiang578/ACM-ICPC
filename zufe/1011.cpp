#include<stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if(n%5==0)
        printf("%d is a multiple of 5.\n",n);
        else
        printf("%d is not a multiple of 5.\n",n);
    }
    return 0;
}
