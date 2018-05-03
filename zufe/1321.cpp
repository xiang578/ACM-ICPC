#include<stdio.h>
int main()
{
    int n,i,b,c;
    double a,x,y;
    while (scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        else
        {
            c=0;
            b=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x,&y);
            a=x*x+y*y;
            if(a>b) {c=i;b=a;}
        }
        printf("%d\n",c);}
    }

    return 0;
}
