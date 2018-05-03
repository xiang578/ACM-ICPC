#include<stdio.h>
int main()
{
    int i;
    for (i=10;i<1000;i++)
    {
        if(i%42==0) printf("%d\n",i);
    }

  return 0;
}
