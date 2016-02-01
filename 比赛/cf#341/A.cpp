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
    int n,i;
    ll ans,mi,t;
    while(~scanf("%d",&n))
    {
        ans=0;
        mi=-1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&t);
            ans+=t;
            if(t%2)
            {
                if(mi==-1) mi=t;
                else mi=min(t,mi);
            }
        }
        if(ans%2)
        {
            if(mi==-1) ans=0;
            else ans-=mi;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
