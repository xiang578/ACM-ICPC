#include<stdio.h>
int main()
{
    char a[150],c[300];
    int i,j,k,t,g,m;
    scanf("%d\n",&t);
    while(t--)
    {
        gets(a);
        g=a[0];k=1;m=0;
        for(i=1;a[i]!=0;i++)
        {
            if(a[i]==g) k++;
            else
            {
                c[m]=k+48;c[m+1]=g;m+=2;
                g=a[i];k=1;
            }
        }
        c[m]=k+48;c[m+1]=g;m+=2;
        for(i=0;i<m;i++)
            printf("%c",c[i]);
        printf("\n");
    }
    return 0;
}
