#include "stdio.h"
#include "string.h"
int main()
{
    int cas,i,len,cnt;
    char s[5000];
    while(~scanf("%d%*c",&cas))
    {
        for(i=0;i<cas;i++)
        {
        scanf("%s",s);
        len=strlen(s);
        cnt=s[len-1]-48;
        if(cnt%2==0) printf("even\n");
        else printf("odd\n");
        }
    }
    return 0;
}
