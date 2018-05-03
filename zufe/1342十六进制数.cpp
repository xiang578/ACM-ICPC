#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double b,i;
    char s[1024];
    while(gets(s))
    {

        if(s[0]=='0') break;
        b=0;
        int len=strlen(s);
        double t=0;
        for(i=len-1;i>=0;i--,t++)
        {
            if(s[i]=='1')
                b+=pow(2,t);
        }
        printf("%X\n",b);
    }
    return 0;
}
