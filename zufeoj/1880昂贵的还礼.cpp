#include<stdio.h>
int main()
{
    int a,b,s,i,t;
    while(~scanf("%d%d",&a,&b))
    {
        s=1,t=1;
        if(a==0&&b==0) break;
        for(i=1;i<b;i++)
        {
            s=s*a%10;
            t+=s;
            t%=10;
        }
        printf("%d\n",t);
    }
    return 0;
}
