#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[1000];
    int i,len,f;
    while(gets(s))
    {
        if(s[0]=='0') break;
        len=strlen(s);
        f=0;
        for(i=len-1;i>=0;i--)
        {
            if(s[i]=='0'&&f==0) continue;
            else
            {f=1;printf("%c",s[i]);}
        }
        printf("\n");
    }
    return 0;
}
