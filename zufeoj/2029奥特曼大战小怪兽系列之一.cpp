#include<stdio.h>
int main()
{
    int  a,b,c,d;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        if(a>=d&&c>b) printf("atm winer\n");
        if(a<d&&c<=b) printf("xgs winer\n");
       if(a>=d&&c<=b) printf("atm and xgs are died\n");
        if(a<d&&c>b)printf("see you next time\n");

    }
    return 0;
}
