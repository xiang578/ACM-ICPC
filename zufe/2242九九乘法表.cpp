#include "stdio.h"
#include "string.h"
int main()
{
	int s[15][15];
	int i,j,n;
	while(~scanf("%d",&n))
	{
		printf("  *");
		for(i=1;i<=n;i++) printf("%3d",i);
			printf("\n");
		for(i=1;i<=n;i++)
		{
			printf("%3d",i);
			for(j=1;j<=i;j++)
				printf("%3d",i*j);
			printf("\n");
		}
	}
	return 0;
}
