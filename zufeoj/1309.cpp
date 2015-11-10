#include<stdio.h>
int main()
{
  int m,n;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
      if(m!=0&&n!=0)
      {
          int i=0,j;
          for(j=1;j<=m;j++)
          {
              i+=j;
              while(i>=n) i-=n;
          }
        printf("%d\n",i);
      }
      else break;
  }
  return 0;
}
