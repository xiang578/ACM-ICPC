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
const int N=2*1e5+10;
int u[N],dp[N],son[N],st,n,m;
vector<int>g[N];

void dfs(int x,int fa)
{
    if(u[x]) son[x]=1;
    else son[x]=0;
    for(int i=0; i<g[x].size(); i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        dfs(y,x);
        son[x]+=son[y];
    }
    //printf("%d %d\n",x,son[x]);
    if(son[x]>=m&&st==-1)
    {
        st=x;
    }
}

void dfs2(int x,int fa,int cnt)
{
    dp[x]=cnt;
    for(int i=0; i<g[x].size(); i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        dfs2(y,x,cnt+1);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d%d",&n,&m);
    memset(u,0,sizeof(u));
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=2*m; i++)
    {
        scanf("%d",&t);
        u[t]=1;
    }
    for(int i=1; i<n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    st=-1;
    dfs(1,0);
    //printf("%d\n",st);
    dfs2(st,0,0);
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(u[i]) ans+=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}
