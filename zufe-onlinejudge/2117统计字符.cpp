#include<stdio.h>
#include<string.h>
int main()
{
    int t,b,i,c;
    char s[120];
    int a[30];
    while(~scanf("%d\n",&t))
    {
        while(t--)
        {
            gets(s);
            for(i=0; i<28; i++) a[i]=0;
            int len=strlen(s);
            for(i=0; i<len; i++)
            {
                a[s[i]-97]++;
            }
            b=0;
            for(i=0; i<27; i++)
                if(a[i]>=b)
                {
                    b=a[i];
                    c=i;
                }
            printf("%c\n",c+97);
        }
    }
    return 0;
}
