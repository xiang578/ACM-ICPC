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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll d,k,a,b,t,l,r,ans1,ans2,n,s;
    cin>>d>>k>>a>>b>>t;
    l=0;
    if(d%k==0) r=d/k;
    else r=d/k+1;
    ans1=d*b;

    while(l<=r)
    {
        ll m=(r+l)/2;
        n=(m+1)*k;
        if(n>d) n=d;
        s=(d-n)*b+n*a+m*t;
        if(s>=ans1)
        {
            l=m+1;
        }
        else
        {
            ans1=s;
            l=m;
        }
    }

     l=0;
    if(d%k==0) r=d/k;
    else r=d/k+1;
    ans2=d*b;
    while(l<=r)
    {
        ll m=(r+l)/2;
        n=(m+1)*k;
        if(n>d) n=d;
        s=(d-n)*b+n*a+m*t;
        //printf("%lld %lld %lld %lld %lld\n",l,r,m,s,ans2);
        if(s>=ans2)
        {
            r=m-1;
        }
        else
        {
            ans2=s;
            r=m;
        }
    }
    ll ans=min(ans1,ans2);
    cout<<min(ans,d*b)<<endl;
    return 0;
}
