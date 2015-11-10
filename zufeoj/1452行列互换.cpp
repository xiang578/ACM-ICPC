#include<stdio.h>
int main()
{
   int c[3][3],a[3][3],i,j;
   for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
        scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
        c[j][i]=a[i][j];
  }
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
       if(j!=2) printf("%d ",c[i][j]);
       else printf("%d \n",c[i][j]);
    }
  }

    return 0;
}
