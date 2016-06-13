/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=100000+10;
ll a[N];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	ll h,k;
	while(~scanf("%d%lld%lld",&n,&h,&k)) {
		for(int i=0; i<n; i++)
			scanf("%lld",&a[i]);
		ll ans=0,tmp=0,t;
		for(int i=0; i<n; i++) {
			while(tmp+a[i]>h) {
				t=tmp+a[i]-h;
				if(t%k==0) {
					ans+=t/k;
					tmp-=t;
				} else {
					ans+=(t/k+1);
					tmp-=k*(t/k+1);
				}
				if(tmp<0) tmp=0;
			}
			tmp+=a[i];
		}
		if(tmp%k==0) ans+=tmp/k;
		else ans=ans+1+tmp/k;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,h,k;
	while(~scanf("%d%d%d",&n,&h,&k))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			//printf("%d\n",i);
		}

		sort(a,a+n);
		int ans=0,tmp=0;
		for(int i=0;i<n;i++)
		{
			while(tmp+a[i]>h)
			{
				tmp-=k;
				ans++;
				if(tmp<0) tmp=0;
			}
			tmp+=a[i];
			//printf("%d\n",i);
		}
		if(tmp%k==0) ans+=tmp/k;
		else ans=ans+1+tmp/k;
		printf("%d\n",ans);
	}
    return 0;
}*/
