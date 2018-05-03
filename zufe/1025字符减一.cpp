#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    while (scanf(" %c",&c)!=EOF)
    {
        c='A'+'Z'-c;
        printf("%c\n",c);
    }
    return 0;
}
