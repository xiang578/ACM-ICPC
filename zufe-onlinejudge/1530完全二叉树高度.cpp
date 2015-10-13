#include "stdio.h"
#include"math.h"
int main()
{
   int ans,n;
    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==0) break;
        while(n>0)
        {
            n=n/2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
