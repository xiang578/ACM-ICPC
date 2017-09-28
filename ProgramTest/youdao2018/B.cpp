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
long long dp[40][40][40][40];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int s,a,b,c,p,i,j,k;
    scanf("%d%d%d%d",&s,&a,&b,&c);
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(p=1;p<=s;p++)
    {
        for(i=0;i<=a;i++)
        {
            for(j=0;j<=b;j++)
            {
                for(k=0;k<=c;k++)
                {
                    if(i-1>=0) dp[p][i][j][k]+=dp[p-1][i-1][j][k];
                    if(j-1>=0) dp[p][i][j][k]+=dp[p-1][i][j-1][k];
                    if(k-1>=0) dp[p][i][j][k]+=dp[p-1][i][j][k-1];

                    if(i>0&&j>0) dp[p][i][j][k]+=dp[p-1][i-1][j-1][k];
                    if(j>0&&k>0) dp[p][i][j][k]+=dp[p-1][i][j-1][k-1];
                    if(i>0&&k>0) dp[p][i][j][k]+=dp[p-1][i-1][j][k-1];

                    if(i>0&&k>0&&j>0) dp[p][i][j][k]+=dp[p-1][i-1][j-1][k-1];
                    dp[p][i][j][k]%=mod;
                    //printf("%d %d %d %d %d\n",p,i,j,k,dp[p][i][j][k]);
                }
            }
        }
    }
    printf("%lld\n",dp[s][a][b][c]);
    return 0;
}
