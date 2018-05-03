#include<stdio.h>
int main()
{
    int m,n,i,x,y;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        x=y=0;
        for(i=m;i<=n;i++)
        {
            if(i%2==0) x+=i*i*i;
             else y+=i*i;
        }
        printf("%d %d\n",y,x);
    }
    return 0;
}
