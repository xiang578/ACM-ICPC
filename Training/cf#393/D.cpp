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
const int inf=1e17;
ll dp[M];
int a[M];

ll get(int i,int x)
{
    x+=1;
    if(x<=0) return 0;
    int k=lower_bound(a,a+i,x)-a;
    //if(a[k]!=x)
        k--;
    //printf("****%d %d %d\n",i,k,x);
    return dp[k];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i]=inf;
    a[0]=0;
    dp[0]=0;
    dp[1]=20;
    cout<<dp[1]<<endl;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+20;
        //50
        if(a[i]-a[i-1]<=90)
        dp[i]=min(dp[i],50+get(i,a[i]-90));
        //100
        if(a[i]-a[i-1]<=1440)
        dp[i]=min(dp[i],120+get(i,a[i]-1440));
        //cout<<dp[i]<<" "<<endl;
        cout<<dp[i]-dp[i-1]<<endl;
    }
    return 0;
}
