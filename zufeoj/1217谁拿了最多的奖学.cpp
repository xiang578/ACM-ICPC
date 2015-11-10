#include<stdio.h>
struct
{
    char name[100];
    int mon;
}d[120];
int main()
{
    int n,t,s,a,b,i,max,c;
    char c1,c2;
    while(~scanf("%d\n",&i))
    {
        s=0,max=0;
        for(n=0;n<i;n++)
        {
            d[n].mon=0;
            scanf("%s%d%d\n%c\n%c%d\n",&d[n].name,&a,&b,&c1,&c2,&c);
            if(a>80&&c>=1) d[n].mon+=8000;
            if(a>85&&b>80) d[n].mon+=4000;
            if(a>90) d[n].mon+=2000;
            if(c2=='Y'&&a>85) d[n].mon+=1000;
            if(c1=='Y'&&b>80) d[n].mon+=850;
            s+=d[n].mon;
            if(d[n].mon>max) {max=d[n].mon;t=n;}
        }
        printf("%s\n%d\n%d\n",d[t].name,d[t].mon,s);
    }
    return 0;
}
