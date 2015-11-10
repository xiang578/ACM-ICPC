#include "stdio.h"
int main()
{
	int n,ans,t;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		ans=0;
		while(n>1)
		{
			if(n==2) {ans+=1;n=1;}
			else
			{
			    t=n/3;
				ans+=t;
				n=n%3+t;
			}

		}
		printf("%d\n",ans );
	}
	return 0;
}
