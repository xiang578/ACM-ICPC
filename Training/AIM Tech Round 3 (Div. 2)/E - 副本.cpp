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
const int N=1e6+10;
vector<int>g[N];
int n,m,ans[N],son[N],f[N],mx[N],mx2[N];

void dfs(int x,int fa)
{
    son[x]=1;
    f[x]=fa;
    int t1=0,t2=0;
    for(int i=0; i<g[x].size(); i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        dfs(y,x);
        son[x]+=son[y];
        if(t1==0||son[t1]<son[y])
        {
            t2=t1;
            t1=y;
        }
        else if(son[t2]<son[y])
        {
            t2=y;
        }
    }
    mx[x]=t1;
    mx2[x]=t2;
}

int check(int x,int s,int k)
{
    //printf("%d %d %d\n",x,s,k);
    if(x==0) return 0;
    if(s!=f[x])
    {
        if(n-son[x]>m) return check(f[x],x,k);
        if(k-(n-son[x])<=m) return 1;
    }
    //printf("  %d %d\n",mx[x],s);
    if(mx[x]!=s&&mx[x]!=0)
    {
        int y=mx[x];
        //if(k-son[y]<=m&&son[y]<=m) return 1;
        //else return check(y,x,son[y]);
        //printf("%d %d\n",k-son[y],m);

        if(son[y]>m) return check(y,x,k);
        else  if(k-son[y]<=m) return 1;

    }
    else if(mx[x]==s&&mx2[x]!=0)
    {

        int y=mx2[x];
        //printf("%d %d\n",k-son[y],y);
        if(k-son[y]>m) return 0;
         if(son[y]>m) return check(y,x,k);
        else if(k-son[y]<=m) return 1;
    }
    /*for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(y==f[x]||y==s) continue;
        if(k-son[y]<=m) return 1;
        if(son[y]>m) return check(y,0,k);
    }*/
    return 0;
}

void get(int x,int fa)
{
    int t=-1;
    if(n-son[x]>m)
    {
        ans[x]=check(fa,x,n-son[x]);
    }
    else
    {
        if(mx[x]==0) ans[x]=1;
        else
        {
            int y=mx[x];
            if(son[y]<=m) ans[x]=1;
            else ans[x]=check(y,x,son[y]);
        }
        /*
        for(int i=0; i<g[x].size(); i++)
        {
            int y=g[x][i];
            if(y==fa) continue;
            if(son[y]>m) {t=y;break;}
        }
        if(t==-1) ans[x]=1;
        else ans[x]=check(t,0,son[t]);
        */
    }
}
int main()
{
    scanf("%d",&n);
    m=n/2;
    int u,v;
    for(int i=1; i<=n+1; i++)
        g[i].clear();
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    son[0]=0;
    dfs(1,0);
    for(int i=1; i<=n; i++)
        get(i,f[i]);
    for(int i=1; i<=n; i++)
        printf("%d ",ans[i]);
    return 0;
}
