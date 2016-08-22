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
ll c[N];
int n,k,t;
int u[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&k);
    memset(u,0,sizeof(u));
    ll tmp=0,tmp2=0,now=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&c[i]);
        tmp+=c[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            sum+=c[i]*c[n];
        }
        else
        {
            sum+=c[i]*c[i-1];
        }
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d",&t);
        u[t]=1;
        tmp2+=c[t];
        now=tmp-tmp2;
        if(t==1)
        {
            if(u[n]==0) now-=c[n];
            if(u[2]==0) now-=c[2];
        }
        else if(t==n)
        {
            if(u[1]==0) now-=c[1];
            if(u[n-1]==0) now-=c[n-1];
        }
        else
        {
            if(u[t+1]==0) now-=c[t+1];
            if(u[t-1]==0) now-=c[t-1];
        }
        sum+=now*c[t];
    }
    cout<<sum<<endl;
    return 0;
}
