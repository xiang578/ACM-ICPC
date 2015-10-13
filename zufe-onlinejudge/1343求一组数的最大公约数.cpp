#include<stdio.h>
#include<string.h>
int p(int a,int b)
{
    int t;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while(a%b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return b;
}
int main()
{
    int n,a[100],i;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int m=p(a[0],a[1]);
        for(i=2;i<n;i++)
        {
            m=p(m,a[i]);
        }
        printf("%d\n",m);
    }
    return 0;
}
