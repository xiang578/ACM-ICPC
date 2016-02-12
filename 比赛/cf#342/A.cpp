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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,a,b,c,ans,t,ans1;
    while(~scanf("%lld%lld%lld%lld",&n,&a,&b,&c))
    {
        ans1=n/a;
        ans=0;
        if(n<b) {printf("%lld\n",max(ans,ans1));continue;}
        t=(n-b)/(b-c);
        n=n-(b-c)*t;
        ans=t;//
        while(n>=b)
        {
            t=n/b;
            ans+=t;
            n=n-t*b+t*c;
        }
        ans+=n/a;
        printf("%lld\n",max(ans,ans1));
    }
    return 0;
}
