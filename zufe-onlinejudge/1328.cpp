#include<stdio.h>
#include<stdlib.h>
int compare( const void *a , const void *b )
        {
        return *(int *)a-*(int *)b;
        }
int main()
{
    int n,m,a[100],s[50],i,v[50],b[50],l=0;
    while (scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            l+=a[i];
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s[i],&v[i]);
            b[i]=1.0*l/v[i]+n+s[i];
        }
        qsort(b,50,sizeof(b[0]),compare);
        printf("%d",b[0]);
    }
    return 0;
}
