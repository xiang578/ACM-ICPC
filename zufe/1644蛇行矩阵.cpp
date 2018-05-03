#include "stdio.h"
int main()
{
	int n,i,j,cnt,f,t,d;
	while(~scanf("%d",&n))
	{
		t=1;
		for(i=1;i<=n;i++)
		{
			cnt=0;
			f=i+1;d=t;
			for(j=0;j<=n-i;j++)
			{
				if(cnt==0)
				{
					printf("%d",d);
					cnt++;
					d+=f;
					f++;
				}
				else
				{
					printf(" %d",d);
					cnt++;
					d+=f;
					f++;
				}
			}
			printf("\n");
			t+=i;
			cnt=0;
		}
	}
	return 0;
}
