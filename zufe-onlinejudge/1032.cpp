#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m;
    char ch[100];
    scanf("%d%*c",&n);
    for(i=1;i<=n;i++)
    {
        gets(ch);
        for (m=0;m<strlen(ch);m++)
        {
            if(ch[m]=='Z') ch[m]='A';
            else ch[m]=ch[m]+1;
        }
        printf("String #%d\n",i);
        puts(ch);
        printf("\n");
    }

    return 0;
}
