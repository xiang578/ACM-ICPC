/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
int dp[4000];
int w[100];

int get(int x)
{
    int i=0,ret=0;
    while(x)
    {
        if(x%2) ret+=w[i];
        x/=2;
        i++;
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,i,j,m,k,t,sum;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        sum=0;
        dp[0]=1;
        for(i=0;i<n;i++)
            sum+=w[i];

        for(i=0;i<n;i++)
        {
            for(j=sum;j>=w[i];j--)
            {
                if(dp[j-w[i]]) dp[j]=1;
            }
        }

        for(i=0;i<n;i++)
            for(j=0;j<=sum-w[i];j++)
        {
            if(dp[j+w[i]]) dp[j]=1;
        }

        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            if(t>sum) puts("NO");
            else if(dp[t]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

