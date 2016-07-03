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
const int N=300000+10;
vector<int>g[N];
int n,q,son[N],fa[N],ans[N];

void dfs(int x)
{
    son[x]=1;
    ans[x]=x;
    for(int i=0; i<g[x].size(); i++)
    {
        int y=g[x][i];
        dfs(y);
        son[x]+=son[y];
    }
    for(int i=0;i<g[x].size();i++)
    {
        if(son[g[x][i]]*2>son[x])
            ans[x]=ans[g[x][i]];
    }
    while(2*(son[x]-son[ans[x]])>son[x])
    {
        ans[x]=fa[ans[x]];
    }
}

int main()
{
    int t;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
        g[i].clear();
    for(int i=2; i<=n; i++)
    {
        scanf("%d",&fa[i]);
        g[fa[i]].push_back(i);
    }
    dfs(1);
    for(int i=0; i<q; i++)
    {
        scanf("%d",&t);
        printf("%d\n",ans[t]);
    }
    return 0;
}
