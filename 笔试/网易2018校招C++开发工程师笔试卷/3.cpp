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

int main()
{
	int n,h[100],ans,a[200],s,t,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",h+i);
	sort(h,h+n);
	ans = 0;
	k = 100;
	s = k,t = k;
	a[k]=h[n-1];
	int l = 0,r = n-2;
	while(l<=r)
	{
		int a1 = abs(h[l]-a[s]);
		int a2 = abs(h[r]-a[s]);
		int a3 = abs(h[l]-a[t]);
		int a4 = abs(h[r]-a[t]);
		if(a1>=max(a2,max(a4,a3)))
		{
			s--;
			a[s]=h[l];
			l++;
			ans+=a1;
		}
		else if(a2>=max(a1,max(a4,a3)))
		{
			s--;
			a[s]=h[r];
			r--;
			ans+=a2;
		}
		else if(a3>=max(a2,max(a1,a4)))
		{
			t++;
			a[t]=h[l];
			l++;
			ans+=a3;
		}
		else if(a4>=max(a2,max(a1,a3)))
		{
			t++;
			a[t]=h[r];
			r--;
			ans+=a4;
		}
	}
	//for(int i=s;i<=t;i++) printf("%d\n",a[i]);
	printf("%d\n", ans);
	return 0;
}