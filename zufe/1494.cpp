#include<stdio.h>
int main()
{
    __int64 m,n;
    while(scanf("%I64dI64%d",&n,&m)!=EOF)
    {
        scanf("I64%d",&m);
        if(n>m) printf("bigger\n");
        else if(m<n)printf("smaller\n");
        else printf("equal\n");
    }
    return 0;
}
