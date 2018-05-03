#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
  char a[1002],b[1000];
  int t;
  cin>>t;
  while(t--)
    {
      scanf("%s%s",a,b);
      if(b[0]>='a'&&b[0]<='z') b[0]+='A'-'a';
      printf("%s%s\n",b,a);
    }
  return 0;
}
