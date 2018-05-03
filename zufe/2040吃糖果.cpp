#include<stdio.h>
int main()
{
    int s,i,j,b,n,m,a[1020],t;
    while(~scanf("%d",&t))
    {
        for(i=0;i<t;i++)
        {
            s=0,b=0;
          scanf("%d",&n);
          for(j=0;j<n;j++)
          {
            scanf("%d",&a[j]);
            if(a[j]>b) b=a[j];
            else s+=a[j];
          }
          if(b>s) printf("No\n");
          else printf("Yes\n");
        }
    }
    return 0;
}
