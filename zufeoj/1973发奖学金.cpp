#include "stdio.h"
#include "string.h"
int main()
{
	int n,sum,a[1000],i;
	while(~scanf("%d",&n))
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=75) sum+=2500;
			else if(a[i]>=70) sum+=1500;
			else if(a[i]>=65) sum+=1000;
			else if(a[i]>=60) sum+=800;
		}
		int j;
		for(i=0;i<n-1;i++)
			for(j=1+i;j<n;j++)
			{
				if(a[j]>a[i])
				{
					int k;
					k=a[i];a[i]=a[j];a[j]=k;
				}
			}
		for(i=0;i<n;i++) printf("%d ",a[i]);
			printf("\n");
		printf("%d\n",sum );
	}
	return 0;
}
