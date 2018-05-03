#include<stdio.h>
int main()
{
    int n,a,b=0,c,i,d=0;
    while (scanf("%d",&n)!=EOF)
    {
        for(i=0;i<12;i++)
        {
            scanf("%d",&a);
            c=n-a+b;
            if(c<0) d+=1;
            b=c;
        }
        printf("%d\n",d);
    }
    return 0;
}
