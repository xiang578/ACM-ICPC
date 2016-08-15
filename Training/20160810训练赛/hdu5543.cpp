/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */
/*
背包,dp[3][2*L],dp[0]代表没有挂在外面的，dp[1]代表一个挂在外面，dp[2]代表两端都有一个挂在外面。将输入的长度都放大两倍即可，之后就是背包了，注意一下不同dp[i]之间的转移就可以了。不知道为什么数组越界在g++下会报出超时。
*/
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
const int N=4048;
const int inf=0x3f3f3f3f;
ll dp[3][N],ans;
int a[N];ll v[N];
int n,m;

int main()
{
    int _,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        m*=2;
        for(int i=0;i<n;i++)
        {
            scanf("%d%lld",&a[i],&v[i]);
            a[i]*=2;
        }
        memset(dp,0,sizeof(dp));
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=2*m) {ans=max(ans,v[i]);continue;}
            //2
            for(int j=m;j>=a[i]/2;j--)
            {
                dp[2][j]=max(dp[2][j],dp[1][j-a[i]/2]+v[i]);
                if(j>=a[i])
                    dp[2][j]=max(dp[2][j],dp[2][j-a[i]]+v[i]);
                ans=max(dp[2][j],ans);
            }

            //1
            for(int j=m;j>=a[i]/2;j--)
            {
                dp[1][j]=max(dp[1][j],dp[0][j-a[i]/2]+v[i]);
                if(j>=a[i])
                    dp[1][j]=max(dp[1][j],dp[1][j-a[i]]+v[i]);
                ans=max(dp[1][j],ans);
            }

            //0
            for(int j=m;j>=a[i];j--)
            {
                dp[0][j]=max(dp[0][j],dp[0][j-a[i]]+v[i]);
                ans=max(dp[0][j],ans);
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
