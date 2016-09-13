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
const int M=1e5+10;
vector<int>g[M];
int vis[M],f[M],cnt[M];
ll ans;

void dfs(int x)
{
    vis[x]=1;
    f[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(y>x) continue;
        if(f[y]==0)dfs(y);
        f[x]=max(f[x],f[y]+1);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        cnt[u]++;
        cnt[v]++;
        if(u<v) swap(u,v);
        g[u].push_back(v);
    }
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    ans=0;
    for(int i=n;i>=1;i--)
    {
        if(vis[i]==0&&g[i].size()!=0)
            dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(ll)f[i]*cnt[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

/*
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
const int M=1e5+10;
vector<int>g[M];
int vis[M],f[M],cnt[M];
ll ans;

void dfs(int x,int d)
{
    vis[x]=1;
    ans=max(ans,(ll)d*cnt[x]);
    if(ans>=cnt[x])
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(y<x||f[y]>=d) continue;
        f[y]=d;
        dfs(y,d+1);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        cnt[u]++;
        cnt[v]++;
        if(u>v) swap(u,v);
        g[u].push_back(v);
    }
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&g[i].size()!=0)
            dfs(i,1);
    }
    printf("%lld\n",ans);
    return 0;
}*/
