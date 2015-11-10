#include<stdio.h>
int main()
{
    int a[100004],n,i,m,j,c,d,t,s;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
          scanf("%d%d",&c,&d);
          s=0;
          for(t=c;t<=d;t++)
            s+=a[t];
            printf("%d\n",s);
        }
    }
    return 0;
}
