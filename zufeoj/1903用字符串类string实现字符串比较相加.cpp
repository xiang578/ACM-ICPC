#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s2[200],s1[200];
    while(~scanf("%s %s",s1,s2))
    {
        printf("%s%s\n",s1,s2);
        if(strcmp(s1,s2)>0) printf("%s\n",s1);
        else printf("%s\n",s2);
    }
    return 0;
}
