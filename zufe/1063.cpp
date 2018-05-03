/*
#include "stdio.h"
#include "string.h"
int main()
{
	char s[100];
	int i,cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%s\n",s);
		int len=strlen(s);
		int ans=0;
		for(i=0;i<len;i++)
		{
			ans=ans*10+(s[i]-96)*(s[i]-96);
		}
		printf("%d\n", ans%101);
	}
	return 0;
}
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int k;
    int daan;
    int sum=0;
    int i;
    int e;
    int q=1;
    int ww,pp;
    char s[1000];
    scanf("%d\n",&ww);
    for(pp=0;pp<ww;pp++)
    {
        sum=0;q=1;
        gets(s);
        for(i=0;i<strlen(s);i++)
        {
            q=1;
            k=(s[i]-'a'+1)*(s[i]-'a'+1);
            e=k;
            while(e>0)
            {
                e=e/10;
                q=q*10;
            }
            sum=sum*q+k;
        }
        daan=sum%101;
        printf("%d\n",daan);
    }
    return 0; 
}

