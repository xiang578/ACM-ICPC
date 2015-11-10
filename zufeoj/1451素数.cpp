#include<stdio.h>
#include<math.h>
int prime(int x)
{
    int k=sqrt(x),i;
    for(i=2;i<=k;i++)
    {
        if(x%i==0)
            break;
    }
    if(i>k) return 1;
    else return 0;
}
int main()
{
    int m;
    while(~scanf("%d",&m))
    {
        if(prime(m)==1) printf("prime");
        else printf("not prime");
    }
    return 0;
}
