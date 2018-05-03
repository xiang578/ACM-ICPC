#include "stdio.h"
int main()
{
	int cas,a,b;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&a,&b);
		if(a!=b&&a-2!=b) printf("No Number\n");
		else
		{
			if(a==b&&a%2==0) printf("%d\n",a+b);
			else if(a==b&&a%2!=0) printf("%d\n",a+b-1);

			if(a-2==b&&a%2==0) printf("%d\n",a+b);
			else if(a-2==b&&a%2!=0)printf("%d\n",a+b-1);

		}
	}
	return 0;
}
