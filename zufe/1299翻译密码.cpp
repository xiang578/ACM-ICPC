#include<stdio.h>
int main()
{
    int n,c,i;
    char a[200];
    while(~scanf("%d",&n)){
    while(n--)
    {
        scanf("%d",&c);
        getchar();
        gets(a);
        if(c==0) puts(a);
        else
            {
                for(i=0;a[i]!=0;i++)
                {
                    if(a[i]>='a'&&a[i]<'z') a[i]=a[i]+1;
                    else if(a[i]=='z') a[i]='a';
                    else if(a[i]>='A'&&a[i]<'Z') a[i]=a[i]+1;
                    else if(a[i]=='Z') a[i]='A';
                }
                puts(a);
            }
    }
    }
    return 0;
}
