#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    char s[1024];
    while(~scanf("%d",&n))
    {
        scanf("%s",&s);
        if(n==0) break;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(i) printf(" ");
            printf(" ");
            for(int j=0; j<n; j++)
            {
                if(s[i]=='1'||s[i]=='4')
                    printf(" ");
                else
                    printf("-");
            }
            printf(" ");
        }
        printf("\n");

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<len; i++)
            {
                if(i) printf(" ");
                if(s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='8'||s[i]=='9'||s[i]=='0')
                    printf("|");
                else printf(" ");
                for(int j=0; j<n; j++)
                    printf(" ");
                if(s[i]!='6'&&s[i]!='5')
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
        }
        //
        for(int i=0; i<len; i++)
        {
            if(i) printf(" ");
            printf(" ");
            for(int j=0; j<n; j++)
            {
                if(s[i]=='1'||s[i]=='7'||s[i]=='0')
                    printf(" ");
                else
                    printf("-");
            }
            printf(" ");
        }
        printf("\n");
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<len; i++)
            {
                if(i) printf(" ");
                if(s[i]=='2'||s[i]=='8'||s[i]=='6'||s[i]=='0')
                    printf("|");
                else
                    printf(" ");
                for(int j=0; j<n; j++)
                    printf(" ");
                if(s[i]!='2')
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
        }
        //
        for(int i=0; i<len; i++)
        {
            if(i) printf(" ");
            printf(" ");
            for(int j=0; j<n; j++)
            {
                if(s[i]=='1'||s[i]=='4'||s[i]=='7')
                    printf(" ");
                else
                    printf("-");
            }
            printf(" ");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
