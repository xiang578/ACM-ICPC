#include<stdio.h>
int main()
{
    int m,n,i,t;
    while(~scanf("%d %d",&n,&m))
    {
        int f=0;
        if(n==0&&m==0) break;
        if(m%2!=0||2*n>m||m>4*n) {printf("Error\n");continue;}
        t=(m-2*n)/2;
        if((m-2*n)%2!=0) printf("Error\n");
        else printf("%d %d\n",n-t,t);
    }
    return 0;
}
