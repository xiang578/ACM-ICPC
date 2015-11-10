#include<stdio.h>
int main()
{
    char a[300];
    while(gets(a))
    {
        if(a[0]=='#') break;
        int i,s;
        s=0;
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]!=32) s+=(i+1)*(a[i]-64);
        }
        printf("%d\n",s);
    }
    return 0;
}
