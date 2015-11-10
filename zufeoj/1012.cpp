#include<stdio.h>
int main()
{
    int n,j;
    while (scanf("%d",&n)!=EOF)
    {
        j=n%7;
        if(j==0) j=7;
        printf("j=%d\n",j);
    }
    return 0;
}
