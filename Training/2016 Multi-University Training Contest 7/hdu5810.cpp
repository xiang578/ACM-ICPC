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
    long long a,b,n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        if(n==0||m==0) break;
        a=n*(m-1);
        b=m*m;
        ll tmp=__gcd(a,b);
        if(tmp==0||a==0) printf("0/1\n");
        else printf("%lld/%lld\n",a/tmp,b/tmp);
    }
    return 0;
}
