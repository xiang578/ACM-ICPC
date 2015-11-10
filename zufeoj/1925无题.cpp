#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char a[500],c[500];
    while(~scanf("%s",a))
    {
        j=0;
        int l=strlen(a);
        if(a[0]=='E'&&a[1]=='N'&&a[2]=='D'&&l==3) break;
        for(i=0;a[i]!=0;i++)
        {
            if(a[i]>='A'&&a[i]<='Z')
            {c[j]=a[i];j++;}
        }
        for(i=0;a[i]!=0;i++)
        {
            if(a[i]>='a'&&a[i]<='z')
            {c[j]=a[i];j++;}
        }
        for(i=0;a[i]!=0;i++)
        {
            if(a[i]>='0'&&a[i]<='9')
            {c[j]=a[i];j++;}
        }
        c[j]=0;
        puts(c);
    }
    return 0;
}
