#include<bits/stdc++.h>
using namespace std;
char s[100000+10];
int main()
{
    scanf("%s",s);
    printf("%s",s);
    int len=strlen(s);
    for(int i=len-1;i>=0;i--)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
