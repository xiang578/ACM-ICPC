#include<stdio.h>

int main()
{
    int a[10],i,s,m,t;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0) t=a[i];
        else t=-a[i];
        if(i==0) m=a[0];
        if(m>t) {m=t;s=i;}
    }
    t=a[s];
    a[s]=a[9];
    a[9]=t;
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[9]);
 return 0;
}
