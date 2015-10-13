#include "stdio.h"
#include "string.h"
int main()
{
    int len,ans,i,a,b,c,cnt;
    char s[100],f;
    ans=0;
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        a=b=c=0;
        cnt=0;
        if(s[len-1]=='?') ans++;
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]>='0'&&s[i]<='9'&&cnt==0) a=a*10+s[i]-48;
                if(s[i]=='+'||s[i]=='-') {f=s[i];cnt++;}
                if(s[i]>='0'&&s[i]<='9'&&cnt==1) b=b*10+s[i]-48;
                if(s[i]=='=') cnt++;
                if(s[i]>='0'&&s[i]<='9'&&cnt==2) c=c*10+s[i]-48;
            }
            if(f=='+') if(a+b!=c) ans++;
            if(f=='-') if(a-b!=c) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
