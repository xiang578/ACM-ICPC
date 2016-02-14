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
    ll a1,a2,b1,b2,t1,t2;
    while(~scanf("%lld%lld%lld%lld",&a1,&b1,&a2,&b2))
    {
        t1=a2-a1;
        t2=b2-b1;
        if(t1<0) t1=-t1;
        if(t2<0) t2=-t2;
        printf("%lld\n",max(t1,t2));
    }
    return 0;
}
