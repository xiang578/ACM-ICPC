#include<stdio.h>
int f(int a,int b)
{
	if(a>b) return a;
	return b;
}
int main()
{
	int dp[20010],v,n,a[35],i,j;
	while(~scanf("%d",&v))
	{
	    scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<20010;i++) dp[i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=v;j>=a[i];j--)
			dp[j]=f(dp[j],dp[j-a[i]]+a[i]);
		}
		printf("%d\n",v-dp[v] );
	}
	return 0;
}
