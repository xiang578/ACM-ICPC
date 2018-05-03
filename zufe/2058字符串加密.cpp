#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char hu[28]={"VWXYZABCDEFGHIJKLMNOPQRSTU"};
    char s[120];
    int i,len;
    while(gets(s))
    {
        if(strcmp(s,"ENDOFINPUT")==0) break;
        gets(s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]=hu[s[i]-65];
            }
        }
        puts(s);
        gets(s);
    }
    return 0;
}
