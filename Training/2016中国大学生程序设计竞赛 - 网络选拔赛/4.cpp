#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int num[20];

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",sum/2);
	}
	return 0;
}
