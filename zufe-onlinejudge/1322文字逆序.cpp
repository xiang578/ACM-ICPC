#include<stdio.h>
#include<string.h>
int main()
{
    char a[120];
    while(gets(a))
    {
        int i,l=strlen(a);
        if(a[0]=='.') break;
        for(i=l-2;i>=0;i--)
            printf("%c",a[i]);
        printf(".\n");
    }
    return 0;
}
