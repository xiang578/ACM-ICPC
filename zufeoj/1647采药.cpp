#include<stdio.h>
int f(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int t,m,d[1024],s[1050],a[1050],i,j,k;
    while(~scanf("%d%d",&t,&m))
    {
        for(i=0;i<1020;i++) d[i]=0;
        for(i=0;i<m;i++)
            scanf("%d%d",&s[i],&a[i]);
        for(i=0;i<m;i++)
        for(j=t;j>=s[i];j--)
            d[j]=f(d[j],d[j-s[i]]+a[i]);
        printf("%d\n",d[t]);
    }
    return 0;
}
