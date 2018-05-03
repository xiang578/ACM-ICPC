#include<stdio.h>
#include<stdlib.h>
int compare(const void*a,const void*b)
{
    return*(int*)a-*(int*)b;
}
int main()
{
    int a[10],i,s,n;
        for(i=0;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,10,sizeof(a[0]),compare);
        for(i=0;i<10;i++)
            {
                printf("%d\n",a[i]);
            }
    return 0;
}
