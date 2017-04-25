#include <bits/stdc++.h>
using namespace std;

int a[123456];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int t=a[0];
		for(int i=1;i<n;i++) t=__gcd(t,a[i]);
	if(t!=1) printf("YES\n0");
	else
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==1)
			{
				if(i+1<n)
				{
					if(a[i+1]%2==1) ans+=1;
					else ans+=2;
					i++;
				}
				else
				{
					ans+=2;
				}
			}
		}
		printf("YES\n%d\n",ans);
	}
	return 0;
}
