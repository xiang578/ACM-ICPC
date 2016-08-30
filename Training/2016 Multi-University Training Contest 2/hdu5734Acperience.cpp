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
    long long a,b,n,t,ans1,ans2,tmp;
    scanf("%d",&_);
    while(_--)
    {
        a=b=0;
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&t);
            b+=t*t;
            if(t<0) a+=t;
            else a-=t;
        }
        //if(a>0) {printf("%lld/1\n",b);continue;}
        ans1=n*b-a*a;
        ans2=n;
        tmp=__gcd(ans1,ans2);
        printf("%lld/%lld\n",ans1/tmp,ans2/tmp);
    }
    return 0;
}
