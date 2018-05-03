#include<stdio.h>
int main()
{
    char a[100];
    while(gets(a))
    {
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='v') a[i]='d';
        else if(a[i]=='d') a[i]='v';
        else if(a[i]=='w') a[i]='e';
        else if(a[i]=='e') a[i]='w';
        else if(a[i]>='a'&&a[i]<='z') a[i]='z'-a[i]+'a';
    }
    puts(a);
    }
    return 0;
}
