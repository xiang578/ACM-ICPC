#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,i,t,m;
    while(~scanf("%d",&n))
    {
        t=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            if(m%215==0) t++;
        }
        printf("%d\n",t);
    }
    return 0;
}
