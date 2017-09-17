#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long x,f,d,p;

int main()
{
	scanf("%lld%lld%lld%lld",&x,&f,&d,&p);
	long long l=0,r=d/x;
	long long ans = 0;
	while(l<=r)
	{
		long long m = (l+r)/2;
		long long cost = m * x + max(0LL,(m - f)) * p;
		//printf ("%lld %lld %lld %lld\n",l,r,m,cost);
		if(cost <= d)
		{
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	printf("%lld\n",ans);
	return 0;
}