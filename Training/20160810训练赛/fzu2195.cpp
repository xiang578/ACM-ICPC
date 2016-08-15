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
const int N=1e5+10;
int n;
struct node
{
    int to,w;
};
vector<node>g[N];
int mx;
void dfs(int x,int t)
{
    mx=max(t,mx);
    for(int i=0;i<g[x].size();i++)
    {
        dfs(g[x][i].to,t+g[x][i].w);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            g[i].clear();
        int u,v,w;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node tmp;
            tmp.to=v;
            tmp.w=w;
            g[u].push_back(tmp);
            ans+=w;
        }
        mx=0;
        dfs(1,0);
        ans-=mx;
        printf("%d\n",ans);
    }
    return 0;
}
