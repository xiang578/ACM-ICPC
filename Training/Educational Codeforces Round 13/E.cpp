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
int n;
double p[20][20];
double dp[1<<18][18];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&p[i][j]);
    memset(dp,0,sizeof(dp));
    int up=(1<<n)-1;
    dp[1][0]=1;
    for(int i=1;i<=up;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&&(1<<j))
            {
                for(int k=0;k<n;k++)
                {
                    if((i&&(1<<k)&&k!=j))
                        //continue;
                    dp[i][j]=max(dp[i][j],p[j][k]*dp[i^(1<<k)][j]+p[k][j]*dp[i^(1<<j)][k]);
                }
            }
        }
    }
    /*
    for(int i=1;i<=up;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) continue;
            for(int k=0;k<n;k++)
            {
                if(i&(1<<k))
                {
                    //dp[i|(1<<j)][j]=max(dp[i|(1<<j)][j],dp[i][k]*p[j][k]);
                    //dp[i|(1<<j)][j]+=dp[i][k]*p[j][k];
                }
            }
        }
    }*/

    /*for(int i=1;i<=up;i++)
    {
        for(int j=0;j<n;j++)
        {
            int k=1<<j;
            if(i&k) use[j]=1;
            else use[j]=0;
        }

        for(int j=0;j<n;j++)
        {
            if(use[j]==1)  continue;
            for(int k=0;k<n;k++)
            {
                if(k==0) continue;
                int t=i+(1<<j);
                dp[t]=max(dp[t],dp[i]*p[j][k]);
            }
        }
    }*/
    double ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[up][i]);
    printf("%.7f\n",ans);
    return 0;
}
