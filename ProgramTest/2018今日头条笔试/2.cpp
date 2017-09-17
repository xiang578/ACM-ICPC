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
const int N = 500000+10;

long long int a[N],s[N];
int l[N],r[N],q[N],cnt;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    s[0] = 0;
    for(int i = 1; i <=n; i++)
    {
    	scanf("%lld",a+i);
    	s[i] = a[i] + s[i-1];
    }
    cnt = -1;
    for(int i = 1;i<=n;i++)
    {
    	while(cnt!=-1&&a[q[cnt]]>a[i])
    	{
    		r[q[cnt]] = i-1;
    		cnt--;
    	}
    	cnt++;
    	q[cnt] = i;
    }
    while(cnt!=-1)
    {
    	r[q[cnt]] = n;
    	cnt--;
    }

    cnt = -1;
    for(int i=n;i>=1;i--)
    {
    	while(cnt!=-1&&a[q[cnt]]>a[i])
    	{
    		l[q[cnt]] = i+1;
    		cnt--;
    	}
    	cnt++;
    	q[cnt] = i;
    }
    while(cnt!=-1)
    {
    	l[q[cnt]] = 1;
    	cnt --;
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
    	ans = max(ans,a[i]*(s[r[i]]-s[l[i]-1]));
    	//printf("%d %d %lld\n",l[i],r[i],a[i]*(s[r[i]]-s[l[i]-1]));
    }
    printf("%lld\n",ans);
    return 0;
}