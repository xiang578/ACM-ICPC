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

double a[100000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n;
    ll x,y,p,len,num;
    double ans;
    while(~scanf("%d%lld",&n,&p))
    {
        rep(i,0,n)
        {
            scanf("%lld%lld",&x,&y);
            len=(y-x+1);
            if(x%p==0)
                x=x/p-1;
            else
                x=x/p;
            y=y/p;
            num=y-x;
            a[i]=1.0*num/len;
        }
        ans=0;
        rep(i,0,n-1)
            ans=ans+(1-(1-a[i])*(1-a[i+1]));
        ans=ans+(1-(1-a[n-1])*(1-a[0]));
        ans=ans*2000;
        printf("%.7f\n",ans);
    }
    return 0;
}
