#include<stdio.h>
int main()
{
    int t,i,n,a[120],b[120],c[120],im,j,am,f;
    char cj[120][30];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        for(i=0; i<n; i++) scanf("%s%d%d%d",cj[i],&a[i],&b[i],&c[i]);
        am=0;
        for(i=0; i<n; i++)
        {
            f=-1;
            if(a[i]>=am)
            {
                for(j=0; j<n; j++)
                {
                    if(a[i]<a[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
                for(j=0; j<n; j++)
                {
                    if(b[i]<b[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
                for(j=0; j<n; j++)
                {
                    if(c[i]<c[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
                    f=0;
                    im=i;
            }
        if(f==0) break;
        }
        if(f==0) printf("%s\n",cj[im]);
        else
            printf("NO NO.1\n");
    }
    return 0;
}
