#include<stdio.h>
int main()
{
    int n,i,s,j;
    while(scanf("%d",&n)!=EOF)
    {
        j=1;
        for(i=0;i<n-1;i++)
        {
            s=2*(j+1);
            j=s;
        }
        printf("%d\n",j);
    }
    return 0;
}
