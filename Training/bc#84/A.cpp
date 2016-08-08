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
    int _;
    ll n,m,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&m,&n);
        ans=0;
        n=min((ll)31,n);
        for(int i=(int)n;i>=0;i--)
        {
            if(m==0) break;
            ll t=1<<i;
            if(t>m) continue;
            ans+=m/t;
            m%=t;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
