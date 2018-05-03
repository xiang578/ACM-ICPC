#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare( const void *a , const void *b )
        {
        return *(int *)b-*(int *)a;
        }
int main()
{
    int s,i,n,a[100];
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        qsort(a,100,sizeof(a[0]),compare);
        s=a[0]+a[1];
        printf("%d\n",s);
    }
    return 0;
}
