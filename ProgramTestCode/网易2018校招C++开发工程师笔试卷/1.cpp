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
const int N = 2e5+10;
int a[N],b[2*N],n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int k = N;
	int s = k,t=k,f=0;
	b[k]=a[0];
	for(int i=1;i<n;i++)
	{
		if(f==0)
		{
			t++;
			b[t]=a[i];
		}
		else
		{
			s--;
			b[s]=a[i];
		}
		f^=1;
	}
	if(f==0)
	{
		for(int i=s;i<=t;i++)
		{
			printf("%d%s",b[i],i==t?"\n":" ");
		}
	}
	else 
	{
		for(int i=t;i>=s;i--)
		{
			printf("%d%s",b[i],i==s?"\n":" ");
		}
	}
	return 0;
}