#include "stdio.h"
int main()
{
	int a,b,c,cas,i,n;
	while(~scanf("%d",&cas))
	{
	    if(cas==0) break;
		a=b=c=0;
		for(i=0;i<cas;i++)
		{
			scanf("%d",&n);
			if(n>0) a++;
			if(n<0) b++;
			if(n==0) c++;
		}
		printf("%d %d %d\n",b,c,a);
	}
	return 0;
}
