#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int cas;
    double t1,t2,x1,x2,y1,y2,a,b,c;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        a=sqrt((x1)*(x1)+(y1)*(y1));
        b=sqrt((x2)*(x2)+(y2)*(y2));
        c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        t1=(a*a+b*b-c*c)/(2*a*b);
        t1=acos(t1);
        printf("%.2f\n",t1*180.00/3.1415926535);
    }
    return 0;
}
