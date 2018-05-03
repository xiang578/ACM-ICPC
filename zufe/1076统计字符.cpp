#include<stdio.h>
int main()
{
    char a[100];
    gets(a);
    int s=0,d=0,f=0,g=0;
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]>='A'&&a[i]<='Z') s++;
        else if(a[i]>='a'&&a[i]<='z')s++;
        else if(a[i]==32) d++;
        else if(a[i]>='0'&&a[i]<='9') f++;
        else g++;
        i++;
    }
    printf("%d\n%d\n%d\n%d\n",s,d,f,g);
    return 0;
}
