#include<stdio.h>
int main()
{
    int n,i,j,s,k;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        s=0;
        while(n>1)
        {
            for(i=2;i<=n;i++)
            {
                if(n%i==0) {s+=i;n=n/i;break;}
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
