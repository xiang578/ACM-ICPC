#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long >a[2];
long long n,x;
long long ans;
int main()
{
	scanf("%lld%lld",&x,&n);
	int k = 0;
	a[k].push_back(0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[k].size();j++)
		{
			a[k][j]++;
			if(a[k][j]>=x) continue;
			a[k^1].push_back(a[k][j]);
			if(a[k][j]>=2) a[k^1].push_back(0);
		}
		sort(a[k^1].begin(),a[k^1].end());
		if(a[k^1].size()>=10)
		{
			a[k^1].pop_back();
			a[k^1].pop_back();
		}
		//for(int j=0;j<a[k^1].size();j++)
		//	printf("%d ",a[k^1][j]);
		//printf("\n");
		a[k].clear();
		k^=1;
	}
	ans=0;
	for(int i=0;i<a[k].size();i++)
	{
		ans+=a[k][i]*2;
	}
	printf("%lld\n",ans);
	return 0;
}