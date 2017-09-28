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
    int n,a[20],dp[300][20],pos[300];
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    memset(pos,0,sizeof(pos));
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        a[i]+=100;
        dp[i][1]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i-1;k>=0;i--)
            {
                if(a[i]>a[k]&&!pos[a[k]])
                {
                    pos[a[k]]=1;
                    dp[i][j]+=dp[k][j-1];
                }
            }
        }
    }
    long long ans=0;
    for(int m=1;m<=n;m++)
    {
        memset(pos,0,sizeof(pos));
        for(int i=n-1;i>=0;i--)
        {
            if(pos[a[i]]) continue;
            pos[a[i]]=1;
            ans+=dp[i][m];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
