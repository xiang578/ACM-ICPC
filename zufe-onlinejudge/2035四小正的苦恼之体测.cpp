#include<stdio.h>
int main()
{
    double n,x,h,w;
    while(~scanf("%lf%lf%lf",&h,&x,&n))
    {
        if(n==1) w=50+x;
        else if(n==2) w=3*x;
        else if(n==3) w=3*(x+50);
        else w=x;
        if(h/w>2) printf("aha,you must treat me.\n");
            else printf("I am sorry.\n");
    }
    return 0;
}
