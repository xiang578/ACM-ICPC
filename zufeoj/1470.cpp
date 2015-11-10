#include "stdio.h"
int main()
{
	int n,m,i;
	char str[1000];
	while(~scanf("%d %s %d",&n,str,&m))
	{
		for(i=m-1;i<n;i++)
			printf("%c",str[i]);
	}
	return 0;
}
