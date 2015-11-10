#include<stdio.h>
int main()
{
    int s,p,a,b,i,j,t,c,n,m;
    while(~scanf("%d%d%d%d",&s,&p,&a,&b))
    {
        t=0;
        j=0;
        if(s==-1&&p==-1&&a==-1&&b==-1) break;
        if(b<2*a)
        {
            if(b<a) {t++;j-=p;}
            if(b==a) {t++;j+=s;}
            if(b>a&&b<2*a){t++;j=s-p;}
        }
        else
        {
            while (b>=2*a)
            {b=b-2*a;t++;j+=2*s;}
            if(b<2*a&&b!=0) {t++;j+=2*s;}
        }
        printf("%d %d\n",t,j);
    }
    return 0;
}
