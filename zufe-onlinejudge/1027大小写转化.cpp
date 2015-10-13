#include<stdio.h>
#include<string.h>
void f(char a[],char b[])
{
    int la=strlen(a);
    int i;
    for(i=0;i<la;i++)
    {
        if(a[i]>='A'&&a[i]<='Z') b[i]=a[i]+32;
        else if(a[i]>='a'&&a[i]<='z') b[i]=a[i]-32;
        else b[i]=a[i];
    }
}
int main()
{
    char a[120],b[120];
    while(gets(a))
    {
    f(a,b);
    int i,la=strlen(a);
    for(i=0;i<la;i++)
    {
        printf("%c",b[i]);
    }
    printf("\n");
    }
    return 0;
}
