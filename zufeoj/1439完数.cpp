#include<stdio.h>
#include<string.h>
int main()
{
    int n,a[100],i,l,j,m,s,t;
    while(~scanf("%d",&n))
    {
        for(i=2;i<=n;i++)
        {
            memset(a,0,sizeof(a));
            s=0;m=0;
            for(j=1;j<i;j++)
            {
                if(i%j==0){a[m]=j;m++;}
            }
            for(t=0;t<m;t++)
            {
                s+=a[t];
            }
            if(i==s)
            {
                printf("%d its factors are ",i);
                for(t=0;t<m;t++)
                {
                    printf("%d ",a[t]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}
