#include "stdio.h"
int main()
{
    int i,a[11],n,j;
    for(i=1; i<=10; i++)scanf("%d",&a[i]);
    n=999999;
    for(i=1; i<=10; i++)
    {
        if(a[i]<n) {n=a[i];j=i;}
    }
    a[j]=a[1];a[1]=n;
    n=-999999;
    for(i=1; i<=10; i++)
    {
        if(a[i]>n) {n=a[i];j=i;}
    }a[j]=a[10];a[10]=n;
    for(i=1; i<=10; i++)printf("%d ",a[i]);
    return 0;
}
