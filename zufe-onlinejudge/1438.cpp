#include<stdio.h>
int main()
{
    int m,n,y,b,c,j,i,s,a[999],t;
        for(i=100;i<=1000;i++)
        {
            y=i/100;
            b=i/10%10;
            c=i%10;
            s=y*y*y+b*b*b+c*c*c;
            if(s==i)
            {
            printf("%d\n",s);
            }
        }
    return 0;
}
