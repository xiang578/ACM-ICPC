#include<stdio.h>
int main()
{
    int t,a,b,c,j,n;
    scanf("%d",&t);
    n=0;
    while(t--)
    {
        n++;
        scanf("%d%d%d%d",&a,&b,&c,&j);
        if(a>=24||b>=60||c>=60)
            {
                printf("Case %d:\n",n);
                printf("u at keng wo!!\n");
            }
        else
            {
                a+=j/3600;j%=3600;
                b+=j/60;j%=60;
                c+=j;
                if(c>=60)
                {
                    b+=c/60;
                    c%=60;
                }
                if(b>=60)
                {
                    a+=b/60;
                    b%=60;
                }
                if(a>=24)
                {
                    a%=24;
                }
                printf("Case %d:\n",n);
                if(a<10) printf("0%d:",a);else printf("%d:",a);
                if(b<10) printf("0%d:",b);else printf("%d:",b);
                if(c<10) printf("0%d\n",c); else printf("%d\n",c);

            }
    }
    return 0;
}
