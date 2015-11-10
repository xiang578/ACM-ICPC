#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,a[100],b,c,i;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&b,&c);
            a[b]++;a[c]++;
        }
        printf("%d",a[1]);
        for(i=2;i<=n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
