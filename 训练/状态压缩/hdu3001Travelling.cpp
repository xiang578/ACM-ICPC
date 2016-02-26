#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int d[12],num[60000][12],dp[60000][12];

int main()
{
    int i,n,m,g[20][20],a,b,w,ans,flag,j,k,news;
    d[0]=1;
    for(i=1;i<=11;i++) d[i]=d[i-1]*3;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                g[i][j]=inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            a--;
            b--;
            g[a][b]=g[b][a]=min(w,g[a][b]);
        }
        for(i=0;i<d[10];i++)
        {
            a=i;
            for(j=0;j<10;j++)
            {
                num[i][j]=a%3;
                a/=3;
            }
        }
        for(i=0;i<d[n];i++)
        {
            for(j=0;j<10;j++)
            {
                dp[i][j]=inf;
            }
        }
        for(i=0;i<n;i++)
            dp[d[i]][i]=0;
        ans=inf;
        for(i=0;i<d[n];i++)
        {
            flag=1;
            for(j=0;j<n;j++)
            {
                if(num[i][j]==0) flag=0;
                if(dp[i][j]==inf) continue;
                for(k=0;k<n;k++)
                {
                    if(g[j][k]==inf||num[i][k]==2) continue;
                    news=i+d[k];
                    dp[news][k]=min(dp[news][k],dp[i][j]+g[j][k]);
                }
            }
            if(flag)
            {
                for(j=0;j<n;j++)
                    ans=min(ans,dp[i][j]);
            }
        }

        if(ans==inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************

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
const int inf=0x7fffffff;
int g[20][20];
int dp[1<<11];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,m,w,a,b,up,i,j,k;
    while(~scanf("%d%d",&n,&m))
	{
	    memset(g,0xff,sizeof(g));
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			if(g[a][b]==-1)
                g[a][b]=g[b][a]=w;
            else
                g[a][b]=g[b][a]=min(g[a][b],w);
		}
		up=(1<<n)-1;
		for(i=0;i<=up;i++)
			dp[i]=inf;
		dp[0]=0;
		for(i=0;i<n;i++)    dp[1<<i]=0;
		for(i=0;i<=up;i++)
		{
			if(dp[i]>=inf) continue;
			for(j=0;j<n;j++)
			{
				if(i&(1<<j)) continue;
				for(k=0;k<n;k++)
				{
					if(!(i&(1<<k))) continue;
					if(g[k+1][j+1]!=-1&&j!=k)
					dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+g[k+1][j+1]);
				}
			}
		}
		//for(i=0;i<=up;i++) printf("%d\n",dp[i]);
		if(dp[up]>=inf) dp[up]=-1;
		cout<<dp[up]<<endl;
	}
    return 0;
}
*/
