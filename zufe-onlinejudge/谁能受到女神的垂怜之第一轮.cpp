#include<stdio.h>
int main()
{
    int n,m,a[104],b[104],i,t,k,l;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        k=0,l=0,t=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>n)break;
            if(k==a[i]){l++;}
            else
            {
                if(k==l)
                {
                    if(t==0)
                    {printf("%d",k);t++;}
                    else printf(" %d",k);
                }
                k=a[i];l=1;
            }
            if(k==l&&a[i]==k)
                {
                    if(t==0)
                    {printf("%d",k);t++;}
                    else printf(" %d",k);
                }

        }
          printf("\n");
          printf("\n");
    }
    return 0;
}
