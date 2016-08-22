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
const int N=1e5+10;
int n;
ll c[N],dp[N][2];
string s[N],t[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",c+i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        t[i]="";
        for(int j=s[i].size()-1;j>=0;j--)
            t[i]+=s[i][j];
    }
    memset(dp,0xff,sizeof(dp));
    dp[0][0]=dp[0][1]=0;
    s[0]=t[0]="";
    int ok=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>=s[i-1]&&dp[i-1][0]!=-1)
        {
            if(dp[i][0]==-1) dp[i][0]=dp[i-1][0];
            else dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }

        if(s[i]>=t[i-1]&&dp[i-1][1]!=-1)
        {
            if(dp[i][0]==-1) dp[i][0]=dp[i-1][1];
            else dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }

        if(t[i]>=s[i-1]&&dp[i-1][0]!=-1)
        {

            if(dp[i][1]==-1) dp[i][1]=dp[i-1][0]+c[i];
            else dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        }

        if(t[i]>=t[i-1]&&dp[i-1][1]!=-1)
        {
            if(dp[i][1]==-1) dp[i][1]=dp[i-1][1]+c[i];
            else dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
        if(dp[i][0]==-1&&dp[i][1]==-1) {ok=0;break;}

    }
    if(!ok) puts("-1");
    else
    {
        ll ans;
        if(dp[n][0]==-1) ans=dp[n][1];
        else if(dp[n][1]==-1) ans=dp[n][0];
        else ans=min(dp[n][1],dp[n][0]);
        printf("%lld\n",ans);
    }
    return 0;
}
