#include<cstdio>
#include<cmath>
int main()
{
    double a,v1,v2;
    while(scanf("%lf %lf %lf",&a,&v1,&v2)!=EOF)
    {
        if(a==0)
            printf("0\n");
        else if(v1*v1-v2*v2>0)
            printf("%lf\n",(a*v1)/(v1*v1-v2*v2));
        else
            printf("Infinity\n");
    }
}
