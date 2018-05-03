#include<stdio.h>
int main()
{
    char a[150],b[150];
    int i,n,j,k,f;
    while(~scanf("%d\n",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s%s",a,b);
            for(j=0;a[j]!='\0';j++)
            {
                f=0;
                for(k=0;b[k]!='\0';k++)
                {
                    if(a[j]==b[k]) {f=1;break;}
                }
                if(f==0) printf("%c",a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
