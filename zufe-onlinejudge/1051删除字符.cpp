#include<stdio.h>
void f(char a[],char b[])
{
    int i,j;
    for(i=0,j=0;b[i]!='\0';i++)
    {
        if(b[i]!=a[0]) printf("%c",b[i]);
    }
    printf("\n");
}
int main()
{
    char a[10],b[100];
    gets(a);
    gets(b);
    f(a,b);
    return 0;
}
