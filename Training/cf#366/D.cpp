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
const int N=5000+10;
ll a[N],b[N],c[N],d[N],x[N],dis[N][N];
int n,s,t,to[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&s,&t);
    rep(i,1,n+1) cin>>x[i];
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) cin>>b[i];
    rep(i,1,n+1) cin>>c[i];
    rep(i,1,n+1) cin>>d[i];

    rep(i,1,n+1)
        rep(j,1,n+1)
        {
            if(i==j) continue;
            if(i<j) dis[i][j]=x[j]-x[i]+d[i]+a[j];
            else dis[i][j]=x[i]-x[j]+c[i]+b[j];
        }
    ll ans=dis[s][t],now;
    to[s]=t;
    rep(i,1,n+1)
    {
        if(i==s||i==t) continue;
        ll mx=1e18;
        int pos;
        for(int u=s;u!=t;u=to[u])
        {
            int v=to[u];
            now=-dis[u][v]+dis[u][i]+dis[i][v];
            if(mx>now)
            {
                mx=now;
                pos=u;
            }
        }
        ans+=mx;
        to[i]=to[pos];
        to[pos]=i;
    }
    cout<<ans;
    return 0;
}
