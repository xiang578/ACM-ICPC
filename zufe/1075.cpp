#include<stdio.h>
int main()
{
    int n,m,tmp,p;
    scanf("%d%d",&n,&m);
    p=n*m;
    while(n!=0)
    {
        tmp=m%n;
        m=n;
        n=tmp;
    }
    printf("%d\n%d\n",m,p/m) ;
    return 0;
}
