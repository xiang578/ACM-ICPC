#include<bits/stdc++.h>
using namespace std;

char s[10024];
int main()
{
    int n,i,len,cnt;
    scanf("%d",&n);
    while(n--)
    {
        cnt=0;
        //scanf("%s",s);
        getchar();
        gets(s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]<0){cnt++;i++;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
