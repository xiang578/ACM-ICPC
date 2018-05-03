#include "stdio.h"
#include "string.h"
int main()
{
	int n,i,j,a[101],b[101],c[101],sa,sb,sc,zf,max;
	char s1[101][20],s2[101][20];
	while(~scanf("%d",&n))
	{
		max=0;
		sa=sb=sc=0;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d%d%d",s1[i],s2[i],&a[i],&b[i],&c[i]);
			if(max<a[i]+b[i]+c[i])
			{
				max=a[i]+b[i]+c[i];
				j=i;
			}
			sa+=a[i];
			sb+=b[i];
			sc+=c[i];
		}
		printf("%d %d %d\n",sa/n,sb/n,sc/n);
		printf("%s %s %d %d %d\n", s1[j],s2[j],a[j],b[j],c[j]);
	}
	return 0;
}
