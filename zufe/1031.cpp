#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double e=0.0,i=1.0;
    printf("n e\n");
    printf("！！！！！！！！！！！！\n");
    for(n=0;n<=9;n++)
    {
        if(n) i=1.0/n*i;
        e+=i;
        if(n==0) printf("%d %.0f\n",n,e);
        else if(n==1) printf("%d %.0f\n",n,e);
        else if(n==2) printf("%d %.1f\n",n,e);
        else  printf("%d %lf\n",n,e);
    }

    return 0;
}
