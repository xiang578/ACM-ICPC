#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,a[105],i,j,max,b;
    while(~scanf("%d",&t))
        while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        max=0;
        for(i=1;i<=n;i++)
            {
                scanf("%d",&b);
                a[b]++;
            }
            for(i=1;i<=n;i++)
            {
                if(a[i]>max) {max=a[i];j=i;}
            }
        printf("%d\n",j);
    }
    return 0;
}
