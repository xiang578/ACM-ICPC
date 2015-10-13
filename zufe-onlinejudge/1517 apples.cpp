#include "stdio.h"
#include<string.h>
int main()
{
    char s[10];
    while(~scanf("%s",s))
    {
        if(strcmp(s,"zero")==0) break;
        if(strcmp(s,"one")==0) printf("one apple\n");
        else printf("%s apples\n",s );
    }
    return 0;
}
