#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    int i;
    while(gets(s))
    {
        if('a'<=s[0]&&s[0]<='z') s[0]-=32;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]==' '&&s[i+1]==' ') {s[i]='.'; s[i+1]='0';}
        }
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='0'&&'a'<=s[i+1]&&s[i+1]<='z') s[i+1]-=32;
        }
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='0') continue;
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
