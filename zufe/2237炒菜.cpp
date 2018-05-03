#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i,j,s,k,a[105],b[105];
    double c[105];
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            c[i]=1.0*b[i]/a[i];
        }
        for(i=0;i<n-1;i++)
            for(j=i;j<n;j++)
            if(c[j]>c[i])
            {
                k=c[j];c[j]=c[i];c[i]=k;
                k=a[j];a[j]=a[i];a[i]=k;
                k=b[j];b[j]=b[i];b[i]=k;
            }
            s=0;
            for(i=0;i<n;i++)
            {
                if(m>=a[i])
                {
                   k=m/a[i];
                   s+=k*b[i];
                   m%=a[i];
                }
            }
            printf("%d\n",s);
    }
    return 0;
}
