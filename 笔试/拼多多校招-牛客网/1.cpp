#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

long long n,a[10000000];

int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	long long  ans = a[0]*a[1]*a[2];
	long long  a1,a2,a3;
	a1=a[0];
	a2=a[1];
	a3=a[2];
	if(a2<a3)
	{
		swap(a2,a3);
	}
	if(a1<a3)
	{
		swap(a1,a3);
	}
	if(a1<a2)
	{
		swap(a1,a2);
	}
	for(int i=3;i<n;i++)
	{
		if(a[i]>a3)
		{
			if(a[i]>a2)
			{
				a3=a2;
				if(a[i]>a1)
				{
					a2=a1;
					a1=a[i];
				}
				else
				{
					a2=a[i];
				}
			}
			else
			{
				a3=a[i];
			}
		}
	}
	ans = max(ans,a1*a2*a3);
	if(a[0]==a1) {
		a2 = a[1];
		a3 = a[2];
	}
	else if(a[1]==a1)
	{
		a2=a[0];
		a3=a[2];
	}
	else
	{
		a2=a[0];
		a3=a[1];
	}
	if(a2>a3) swap(a2,a3);
	for(int i=2;i<n;i++)
	{
		if(a[i]<a3)
		{
			if(a[i]<a2)
			{
				a3=a2;
				a2=a[i];
			}
			else
			{
				a3=a[i];
			}
		}
	}
	ans = max(ans,a1*a2*a3);
	printf("%lld\n",ans);
    return 0;
}