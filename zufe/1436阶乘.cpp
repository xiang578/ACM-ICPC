#include<stdio.h>
int main()
{
    long long int i,n,s=0,m=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        m=i*m;
        s+=m;
    }
    printf("%lld\n",s);

    return 0;
}
