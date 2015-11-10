#include<stdio.h>
int main()
{
 int i;
 double s=0,f=1;
 for (i=1;i<=30;i++)
 {
     f=i*f;
     s+=f;
 }
 printf("%.2e\n",s);
 return 0;
}
