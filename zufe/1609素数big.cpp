#include "stdio.h"
#include "math.h"
#include "string.h"
int main()
{
	int n,i;
	int f[10000001]={0,0,2};
	for(i=3;i<10000001;i++)
    {
        int j,k=sqrt(i);
        for(j=2;j<=k;j++)
        {

            if(i%j==0) break;
        }
        if(j>k) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    }
	while(~scanf("%d",&n))
	{
		printf("%d\n",f[n]);
	}
		return 0;
}
