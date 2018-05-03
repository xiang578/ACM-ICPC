#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,i,j,cnt;
    char s[100];
    while(~scanf("%d",&n))
    {
        getchar();
        cnt=0;
        for(j=0;j<n;j++)
        {
            gets(s);
            for(i=2;i<strlen(s);i++)
            {
                if((s[i-2]=='a'||s[i-2]=='A')&&(s[i-1]=='c'||s[i-1]=='C')&&(s[i]=='m'||s[i]=='M'))
                    {cnt++; break;}
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
