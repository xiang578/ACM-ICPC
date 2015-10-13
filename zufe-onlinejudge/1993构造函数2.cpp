#include "stdio.h"
int main()
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		printf("%d:%d:%d\n",a,b,c );
		printf("0:0:0\n");
	}
	return 0;
}
