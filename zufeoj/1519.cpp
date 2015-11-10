#include<stdio.h>
int main()
{
    long long int a;
    int n,i;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {scanf("%lld",&a);
        a=a%100000+600000;
        printf("%lld\n",a);}
    }
    return 0;
}

