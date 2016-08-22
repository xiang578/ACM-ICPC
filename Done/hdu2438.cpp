#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
double x,y,l,d;

double get(double m)
{
    return l*cos(m)+(d-x*cos(m))/sin(m);
}

int main()
{
    while(~scanf("%lf%lf%lf%lf",&x,&y,&l,&d))
    {
        double a,b,m1,m2;
        a=0;b=acos(-1.0)/2;
        while(b-a>eps)
        {
            m1=(b+2*a)/3;
            m2=(a+2*b)/3;
            double f1=get(m1);
            double f2=get(m2);
            //printf("%lf %lf\n",a,b);
            if(f2>f1)
            {
                a=m1;
            }
            else
            {
                b=m2;
            }
        }
        //printf("%lf\n",get(b));
        if(get(a)<=y) puts("yes");
        else puts("no");
    }
    return 0;
}
