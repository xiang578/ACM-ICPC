#include<stdio.h>
#include<string.h>
int main()
{
    int i,x;
    char k[1001];
    while(~scanf("%s",k))
    {
        x=0;
        int l=strlen(k);
        for(i=0;i<l;i++)
        {
            x=x*10+k[i]-'0';
            x=x%1111;
        }
        if(x==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
