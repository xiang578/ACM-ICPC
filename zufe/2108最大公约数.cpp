#include<stdio.h>
int main()
{
    int a,b,c,i;
    while(~scanf("%d%d",&a,&b))
    {
        if(a<b) {i=a;a=b;b=i;}
        for(i=b;;i--)
        {
            if(a%i==0&&b%i==0) break;
        }

            printf("%d\n",i);
    }
    return 0;
}
