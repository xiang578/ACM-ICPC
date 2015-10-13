#include<stdio.h>
int main()
{
    int m,n,i,j;
    double s,f;
    while(scanf("%d",&n)!=EOF)
    {

        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            f=1.0,s=0.0;
            for(j=1;j<=m;j++)
            {
                s+=f/j;
                f=-f;
            }
            printf("%.2f\n",s);
        }
    }
    return 0;
}
