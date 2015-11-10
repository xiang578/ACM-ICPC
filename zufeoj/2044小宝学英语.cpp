#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,b,c,j;
    char a[1020];
    while(~scanf("%d%*c",&n))
    {
        for(c=0;c<n;c++)
        {
        gets(a);
        b=0;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]==32)
                {
                    for(j=i-1;j>=b;j--){printf("%c",a[j]);}
                    printf(" ");
                    b=i+1;
                }
            if(i==(strlen(a)-1))
            {
            for(j=i;j>=b;j--){printf("%c",a[j]);}
            }
        }
        printf("\n");
        }
    }
    return 0;
}
