#include<stdio.h>
int main()
{
  int a,b,s,i;
  while(scanf("%d",&a)&&a)
  {
    s=0;
    for(i=1;i<=a;i++)
    {
      scanf("%d",&b);
      s+=b;
    }
    printf("%d\n",s);
  }
 return 0;
}
