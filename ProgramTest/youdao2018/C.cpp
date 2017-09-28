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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,x;
    scanf("%d%d\n",&n,&x);
    long long dp[30][200];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n*6;j++)
        {
            if(dp[i-1][j]==0)  continue;
            for(int k=1;k<=6;k++)
            {
                dp[i][j+k]+=dp[i-1][j];
            }
        }
    }
    long long a=0;
    for(int i=x;i<=n*6;i++)
    {
        a+=dp[n][i];
    }
    long long b=1;
    for(int i=1;i<=n;i++)
    {
        b*=6;
        long long t=__gcd(a,b);
        a/=t;
        b/=t;
        printf("%lld %lld\n",a,b);
    }
    printf("%lld/%lld\n",a,b);
    return 0;
}
