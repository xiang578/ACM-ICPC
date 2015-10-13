#include<stdio.h>
int m[41];
int f(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else
    {
        if(m[n]) return m[n];
        m[n]=f(n-2)+f(n-1);
    }
    return m[n];

}
int main()
{
    int n,i,j;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        printf("%d\n",f(n));
    }
    return 0;
}
