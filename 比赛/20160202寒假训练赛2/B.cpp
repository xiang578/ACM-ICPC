/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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

ll pow_mod(ll a,ll n)
{
    if(n==0) return 1;
    ll x=pow_mod(a,n/2);
    ll ret=x*x%mod;
    ret=ret%mod;
    if(n%2==1) ret=ret*a%mod;
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,m,ans,i,a,b;
    while(~scanf("%lld%lld",&n,&m))
    {
        ans=pow_mod(2,n-2);
        printf("%lld\n",ans);
    }
    return 0;
}
