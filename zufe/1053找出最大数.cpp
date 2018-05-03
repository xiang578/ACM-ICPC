#include<stdio.h>
int main()
{
    int n,j,i;
    float  a,x,s;
    while(~scanf("%d",&n))
    {
        x=-1111111111111;
        s=111111111111;
        for(i=0;i<n;i++)
        {
            scanf("%f",&a);
            if(a>x) x=a;
            if(a<s) s=a;
        }
        printf("%.2f %.2f\n",x,s);
    }
    return 0;
}
