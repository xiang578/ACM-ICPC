#include<stdio.h>
int main()
{
    {int m,f,j,n,i;
    double s;
    while(scanf("%d",&m)!=EOF)
    {

        for(i=0;i<m;i++)
        {scanf("%d",&n);
            f=1,s=0;
            for(j=1;j<=n;j++)
            {
            s+=1.0/j*f;f=-f;
            }
            printf("%.2f\n",s);
        }
    }
    return 0;
    }
}
