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
int n;
map<int,ll>mp;
ll ans,a,b;
void dfs(int x,ll m)
{
    //printf("%d %lld\n",x,m);
    ll t;
    int y;
    if(m>ans) return ;
    if(x==0) {ans=min(ans,m);return;}
    if(x%2==0)
    {
        y=x/2;
        t=min(m+b,m+a*x/2);
        if((mp[y]!=0&&t<mp[y])||mp[y]==0)
        {
            //printf("   %d %d\n",t, y);
            mp[y]=t;
            dfs(y,t);
        }
    }
    else
    {
        //+1
        y=x/2+1;
        t=min(m+a+b,m+a*y+a);
        if((mp[y]!=0&&t<mp[y])||mp[y]==0)
        {
            mp[y]=t;
            dfs(y,t);
        }
        //-1
        y=x/2;
        t=min(m+a+b,m+a+a*y);
        if((mp[y]!=0&&t<mp[y])||mp[y]==0)
        {
            mp[y]=t;
            dfs(y,t);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%lld%lld",&n,&a,&b);
    mp.clear();
    ans=n*a;
    mp[n]=ans;
    dfs(n,0);
    printf("%lld\n",ans);
    return 0;
}
