#include<stdio.h>
#include<math.h>
double f(double x,double y)
{
    int c=0;
    double a,b;
            a=pow((pow(1-x,2)+pow(-0.5-y,2)),1.0/2);
            b=pow((pow(0.5-x,2)+pow(y,2)),1.0/2);
             if(a<5 && b<6) c=1;
             return c;
}
int main()
{
    int n,i,m;
    double x,y;
    m=0;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
       for(i=1;i<=n;i++)
       {
           scanf("%lf%lf",&x,&y);
           if(f(x,y)) m++;
        }
        printf("%d\n",m);
    }
    return 0;
}
