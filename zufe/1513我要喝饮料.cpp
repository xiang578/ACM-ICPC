#include<stdio.h>
int main()
{
    int n,i,j,s;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        s=n;
        while(n)
        {
            if(n==1) break;
            if(n==2) {s=s+1;break;}
            s+=n/3;
            j=n%3+n/3;
            n=j;
        }
        printf("%d\n",s);
    }
    return 0;
}
