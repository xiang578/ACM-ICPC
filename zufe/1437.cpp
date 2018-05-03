#include<stdio.h>
int main()
{
    double s;
    int a,b,c,i;
    scanf("%d%d%d",&a,&b,&c);
    s=0;
    for(i=1;i<=a;i++)
        {
            s+=i;
        }
    for(i=1;i<=b;i++)
    {
        s+=i*i;
    }
    for(i=1;i<=c;i++)
    {
        s+=1.0/i;
    }
    printf("%.2f\n",s);
    return 0;
}
