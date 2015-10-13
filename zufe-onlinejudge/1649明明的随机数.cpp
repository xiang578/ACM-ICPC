#include<stdio.h>
int main()
{
    int a[105],b[105],n,i,j;

    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i]) {a[j]=a[i]+a[j];a[i]=a[j]-a[i];a[j]=a[j]-a[i];}
        }
        b[0]=a[0];
        j=0;
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1]){j++;b[j]=a[i];}
        }
        printf("%d\n",j+1);
        for(i=0;i<j;i++)
            printf("%d ",b[i]);
        printf("%d\n",b[j]);
    }
    return 0;
}
