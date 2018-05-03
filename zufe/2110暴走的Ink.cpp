/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   int n,a[30],i;
    char s[1024];
    while(scanf("%d\n",&n))
    {
        memset(a,0,sizeof((a)));
        scanf("%s",s);
        if(n<26) printf("YES");
        else
        {
            int m=0;
            for(i=0; s[i]!=0; i++)
            {
                a[s[i]-97]++;
                if(a[s[i]-97]==1) m++;
                if(m==26) break;
            }
            if(m!=26) printf("YES");
            else printf("Poor big pie!");
        }
    }
    return 0;
}*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int i;
    int n;
    while (~scanf("%d", &n))
    {
        int flag = 0;
        int a[1000] = { 0 };
        scanf("%s", s);
        for (i = 0; i < strlen(s); i++) a[s[i]] = 1;
        for (i = 'a'; i <= 'z'; i++)
        {
            if (a[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) printf("YES\n");
        else printf("Poor big pie!\n");
    }
    return 0;
}
