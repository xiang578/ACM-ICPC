#include<stdio.h>
int main()
{
    char a[150];
    int i,j;
    while(gets(a))
    {
        j=0;
        for(i=0;a[i]!='\0';i++)
        {
            if(j==0&&(a[i]>'Z')) a[i]-=32;
            else if(a[i]==32) {j=0;}
            if(a[i]!=32) j++;
        }
      puts(a);
    }
    return 0;
}
