#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,a;
    char s[10124];
    while(gets(s))
    {
        if(s[0]=='0') break;
        int len=strlen(s);
        n=0;
        a=s[len-1]-48;
        a*=5;
        for(i=0; i<len-1; i++)
        {
            n=n*10+s[i]-48;
            n%=17;
        }
        n-=a;
        if(n%17==0) printf("1\n");
        else printf("0\n");
    }
return 0;
}
