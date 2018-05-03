#include "stdio.h"
#include "string.h"
int main()
{
    int sum,i,cnt;
    char s[30];
    while(~scanf("%s",&s))
    {
        int len=strlen(s);
        sum=0;cnt=1;
        for(i=0;i<len-1;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                sum+=(s[i]-48)*cnt;
                cnt++;
            }
        }
        sum%=11;
        if(sum==10)
        {
            if(s[len-1]=='X') printf("Right\n");
            else
            {
                s[len-1]='X';
                printf("%s\n",s);
            }
        }
        else
            if(s[len-1]-48==sum) printf("Right\n");
            else
            {
                s[len-1]=sum+48;
                printf("%s\n",s);
            }
    }
    return 0;
}
