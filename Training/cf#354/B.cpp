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
int dp[20][20];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,t,k,ans;
	while(~scanf("%d%d",&n,&t))
	{
		memset(dp,0,sizeof(dp));
		dp[1][1]=t*1024;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				k=dp[i][j]-1024;
				if(k<0) continue;
				dp[i+1][j]+=k/2;
				dp[i+1][j+1]+=k/2;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(dp[i][j]>=1024) ans++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
