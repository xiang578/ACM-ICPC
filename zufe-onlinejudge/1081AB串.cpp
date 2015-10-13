#include<stdio.h>
#include<string.h>
int main()
{
    char a[102];
    int i,j,t,l;
    while(gets(a))
    {
        j=0;
        l=strlen(a);
        for(i=0;i<=l/2+1;i++)
        {
            if(a[i]=='A') j++;
        }
        t=(j>l-j)?l-j:j;
        printf("%d\n",t);
    }
    return 0;
}
