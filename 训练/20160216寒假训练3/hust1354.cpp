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

int w[N],v[N],c[N],dp[2][10000+5],use[N],sw[N],sv[N];
vector<int>vt[30];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,i,j,k,t,p,x,y,up;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1; i<=n; i++) scanf("%d",&v[i]);
        for(i=1; i<=n; i++) scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        memset(use,0,sizeof(use));
        scanf("%d",&t);
        for(i=1; i<=t; i++)
        {
            vt[i].clear();
            sw[i]=sv[i]=0;
            scanf("%d",&p);
            for(j=0; j<p; j++)
            {
                scanf("%d",&x);
                vt[i].push_back(x);
                sw[i]+=w[x];
                sv[i]+=v[x];
                use[x]=1;
            }
            scanf("%d",&c[i]);
            sw[i]+=c[i];
        }
        for(i=1; i<=n; i++)
        {
            if(use[i]) continue;
            for(j=m; j>=v[i]; j--)
                dp[0][j]=max(dp[0][j],dp[0][j-v[i]]+w[i]);
        }
        for(i=1;i<=t;i++)
        {
            for(j=0;j<=m;j++) dp[1][j]=dp[0][j];
            for(j=0; j<vt[i].size(); j++)
            {
                y=vt[i][j];
                for(k=m; k>=v[y]; k--)
                    dp[1][k]=max(dp[1][k],dp[1][k-v[y]]+w[y]);
            }
            for(j=m;j>=sv[i];j--)
            {
                dp[0][j]=max(dp[0][j],dp[0][j-sv[i]]+sw[i]);
            }
            for(j=0;j<=m;j++)
                dp[0][j]=max(dp[0][j],dp[1][j]);
        }
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
