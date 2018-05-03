#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[1024];
    int len,i,s,t;
    while(gets(a))
    {
        len=strlen(a);
        if(a[0]=='0'&&len==1) break;
        s=0;
        for(i=0;pow(2,i)<len;i++)
        {
            t=pow(2,i);
            s+=a[len-t]-'0';
        }
        printf("%d\n",s);
    }
    return 0;
}
