#include "stdio.h"
#include "string.h"
int main()
{
    int n,i,j,len,a[101],b[101],c[101];
    char str[101][10],s2[101][10];
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
            scanf("%s%s%d%d%d",str[i],s2[i],&a[i],&b[i],&c[i]);
        for(i=0; i<n; i++)
        {
            printf("%s,%s,%d,%d,%d\n",str[i],s2[i],a[i],b[i],c[i]);
        }
    }
    return 0;
}
