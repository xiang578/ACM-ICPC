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
const int N=100000+10;
const int M=1000000+10;
struct node
{
    int u,v,w;
}p[M];
int n,m,use[N],son[N],bin[N];
double ans1;
int cmp(node a,node b)
{
    return a.w<b.w;
}
vector<int>g[N];

int Find(int x)
{
    if(x==bin[x])
        return x;
    else
        return bin[x]=Find(bin[x]);
}

void dfs(int x)
{
    use[x]=1;
    son[x]=1;
    int y,t;
    for(int i=0;i<g[x].size();i++)
    {
        t=g[x][i];
        if(p[t].u==x) y=p[t].v;
        else y=p[t].u;
        if(use[y]==1) continue;
        dfs(y);
        son[x]+=son[y];
        long long tmp=(long long)son[y]*((long long)(n-son[y]));
        ans1+=p[t].w*tmp;
        //printf("%d %d %d %d\n",x,y,p[i].w,son[y]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,u,v;
    long long ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            use[i]=0;
            bin[i]=i;
        }
        ans=0;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
        sort(p,p+m,cmp);
        for(int i=0;i<m;i++)
        {
            u=p[i].u;
            v=p[i].v;
            int fu=Find(u);
            int fv=Find(v);
            if(fu==fv) continue;
            bin[fu]=fv;
            g[u].push_back(i);
            g[v].push_back(i);
            ans+=p[i].w;
        }
        ans1=0;
        dfs(1);
        ans1*=2;
        ans1/=n;
        ans1/=(n-1);
        printf("%lld %.2f\n",ans,ans1);
    }
    return 0;
}
