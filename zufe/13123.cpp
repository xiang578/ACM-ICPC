#include<stdio.h>//ÕıÈ·
int main()
{
    int n,m,a,s,i,v,b,l,sum;
    while (scanf("%d",&n)!=EOF)
    {
        sum=0;
        l=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            l+=a;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s,&v);
            b=1.0*l/v+n+s+2;
            if(b>=sum) sum=b;
        }
        printf("%d\n",sum);
    }
    return 0;
}
