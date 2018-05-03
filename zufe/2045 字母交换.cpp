#include<stdio.h>
int main()
{
    int n,i,t,j;
    char a[100];
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        scanf("%s%*c",a);
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
            if(a[j]-a[i]==32)
            {t=a[j];a[j]=a[i];a[i]=t;break;}
            if(a[i]-a[j]==32)
            {t=a[j];a[j]=a[i];a[i]=t;break;}
        }
        }
        for(i=0;i<n-1;i++)
        printf("%c",a[i]);
        printf("%c\n",a[n-1]);
    }
    return 0;
}
