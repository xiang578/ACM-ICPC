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
const ll inf=1<<60;
ll x[1000000+5],y[1000000+5],a[1000000+5],b[1000000+5];
ll seed;
ll h1,h2;
ll l1,l2;

inline ll rand(ll l, ll r)
{
    static ll mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        cin >> n >> seed;
        h1=h2=-inf;
        l1=l2=inf;
        for (int i = 0; i < n; i++)
        {
            x[i] = rand(-1000000000, 1000000000);
            y[i] = rand(-1000000000, 1000000000);
            a[i]=x[i]+y[i];
            b[i]=x[i]-y[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        ll t1=a[n-1]-a[0];
        ll t2=b[n-1]-b[0];
        if(t1<0) t1=-t1;
        if(t2<0) t2=-t2;
        cout<<max(t1,t2)<<endl;
    }
    return 0;
}
