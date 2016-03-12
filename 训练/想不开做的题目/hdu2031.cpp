#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,r,i,f,a[1024];
    while(~scanf("%d%d",&n,&r))
    {
        m=0;
        if(n<0) f=1,n=-n;
        else f=0;
        if(n==0) {printf("0\n");continue;}
        while(n>0)
        {
            a[m++]=n%r;
            n/=r;
        }
        if(f) printf("-");
        for(i=m-1;i>=0;i--)
        {
            if(a[i]>=0&&a[i]<=9) printf("%d",a[i]);
            else printf("%c",'A'+a[i]-10);
        }
        printf("\n");
    }
    return 0;
}
