#include<stdio.h>
int main()
{
    int a[7][7],i,j,n,m=0,b,c;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                {
                scanf("%d",&a[i][j]);
            if(a[i][j>m]) {m=a[i][j];b=i;c=j;}
            }
        }
        printf("%d %d %d\n",m,b+1,c+1);
    }
 return 0;
}
