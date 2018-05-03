#include<stdio.h>
int main()
{
    int b,i,s,c,a,t;
    while(scanf("%d",&b)!=EOF)
    {
        if(b==0) break;
        else
            {
        c=0,s=0,t=0;
        while(b!=0)
        {
            i=b%2;
            if(i) s++;
            else s=0;
            if(s>t) t=s;
            c++;
            b=b/2;
        }
        printf("%d\n",t);
        }
    }
return 0;
}
