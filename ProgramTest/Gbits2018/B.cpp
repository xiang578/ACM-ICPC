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
const int N=2048;
const int M=1e6+10;
int n,m;
long long a[N][N];
long long dp[N][N];

int ok(long long mid) {
	memset(dp,0xff,sizeof(dp));
	dp[1][1]=mid+a[1][1];
	if(dp[1][1]<=0) return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(i==1) {
				if(dp[i][j-1]<=0) continue;
				dp[i][j] = dp[i][j-1]+a[i][j];
			}
			else if(j==1) {
				if(dp[i-1][j]<=0) continue;
				dp[i][j] = dp[i-1][j]+a[i][j];
				//mi[i][j] = min(dp[i][j],min[i][j-1]);
			}
			else {
				if(dp[i-1][j]<=0&&dp[i][j-1]<=0) continue;
				else if(dp[i][j-1]<=0) dp[i][j] = dp[i-1][j]+a[i][j];
				else if(dp[i-1][j]<=0) dp[i][j] = dp[i][j-1]+a[i][j];
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
				//mi[i][j] = min(dp[i][j],min[i][j-1]);
			}
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	//printf("%d %d\n",mid,dp[n][m]);
	if(dp[n][m]>=0) return 1;
	else return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	long long  l=0,r=1e12+10;
	int ans = 1e12+10;
	while(l<=r) {
		int mid = (l+r)/2;
		if(ok(mid)) {
			ans = min(mid,ans);
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	printf("%lld\n",ans);
    return 0;
}
