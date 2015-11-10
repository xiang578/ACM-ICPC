#include<stdio.h>
int main ()
{
    int a,i,n=0,m=0;
    double s=0.0;
    for(i=0;i<20;i++)
    {
        scanf("%d",&a);
        if(a>0)
        {
            n=n+1;
            s+=a;
        }
        else if(a<0)
        m+=1;
        else
        continue;
    }
     s=1.0*s/n;
    printf("%d\n%.2f\n",m,s);
    return 0;
}
