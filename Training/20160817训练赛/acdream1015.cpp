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
const int N=1e5;
int n,ans,a,b,son[N],t;
vector<int>g[N];

void dfs(int x,int fa)
{
    int mx=0;
    son[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(fa==y) continue;
        dfs(y,x);
        son[x]+=son[y];
        mx=max(mx,son[y]);
    }
    if(mx>=n-son[x])
    {
        ans=max(ans,n-mx);
    }
    else
    {
        ans=max(ans,son[x]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++) g[i].clear();
        ans=1;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
           g[a].push_back(b);
           g[b].push_back(a);
        }
        t=n;
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
