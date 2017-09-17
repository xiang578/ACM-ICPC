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
const int N=20480;
const int M=1e5+10;
int a[N];
int dp[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n = 0;
    char ch;
	while(scanf("%d%c",a+n,&ch)){
		n++;
		if(ch=='\n') break;
	}
	dp[0]=a[0];
	int ans = a[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = max(a[i],dp[i-1]+a[i]);
		ans = max(ans,a[i]);
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
    return 0;
}
