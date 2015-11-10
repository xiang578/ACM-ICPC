
#include<stdio.h>
int main()
{
    {
        int m,f,j,n,i;
        double s;
        while(scanf("%d",&n)!=EOF)
        {
            if(n==0) break;
            f=1,s=0;
            for(j=1; j<=n; j++)
            {
                s+=1.0/j*f;
                f=-f;
            }
            printf("%.3f\n",s);
        }
        return 0;
    }
}
