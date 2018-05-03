#include<stdio.h>
int main()
{
    int i,t,j,f;
    char a[500],c[50]={"qwertyuiopasdfghjklzxcvbnm"};
    char b[50]={"wertyuiopqsdfghjklaxcvbnmz"};
    scanf("%d\n",&t);
    while(t--)
    {
        gets(a);
        f=0;
        for(j=0;a[j]!=0;j++)
        {
            for(i=0;i<26;i++)
            {
                if(b[i]==a[j]) {printf("%c",c[i]);f=1;}
            }
            if(f==1) {f=0;}
            else printf("%c",a[j]);
        }
        printf("\n");
        }
    return 0;
}
