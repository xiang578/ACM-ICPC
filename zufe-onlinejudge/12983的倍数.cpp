#include<stdio.h>
#include<string.h>
int main()
{
    char a[1020];
    while (scanf("%s",a)!=EOF)
    {
        int s=0;
        int i;
        for(i=0;i<strlen(a);i++)
        {
            s+=a[i];
        }
        if(s%3==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;

}
