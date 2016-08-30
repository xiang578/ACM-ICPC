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
const ll mod=100000000;
const int N=10000;
int n,m,ans,ok[N],a[20],dp[20][N];

int get(int x)
{
    int b[20];
    memset(b,0,sizeof(b));
    for(int i=0;i<15;i++)
    {
        if(x&(1<<i)) b[i]=1;
    }
    for(int i=0;i<15;i++)
    {
        if(b[i]&&b[i+1]) return 0;
    }
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout)
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            int t=0,k;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&k);
                t=t*2+k;
            }
            a[i]=t;
        }
        int up=1<<(m+1);
        for(int i=0;i<up;i++)
        {
            ok[i]=get(i);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<up;j++)
            {
                if(!ok[j]) continue;
                int t=j|a[i];
                if(t!=a[i]) continue;
                if(i==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    for(int k=0;k<up;k++)
                    {
                        if(dp[i-1][k]==0) continue;
                        int p=k&j;
                        if(p!=0) continue;
                        dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
                }
                if(i==n-1) ans=(ans+dp[i][j])%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
