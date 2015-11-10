#include<stdio.h>
int main()
{
    int a[105],i,n,s;
    a[1]=1;
    for(i=2;i<102;i++)
    {
        a[i]=a[i-1]+i;
    }
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        s=0;
        for(i=1;i<=n;i++)
        {
            s+=a[i];
        }
        printf("%d\n",s);
    }
        return 0;
}
