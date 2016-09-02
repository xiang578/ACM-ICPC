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
typedef long long ll;
ll a[10000+10];

int main()
{
    int n;
    ll s=0;
    while(~scanf("%d",&n))
    {
        s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        for(int i=1;i<n;i++)
        {
            s+=a[i]-a[0];
        }
        ll b=s,t;
        for(int i=1;i<n;i++)
        {
            t=b+(i-1)*(a[i]-a[i-1])-(a[i]-a[i-1])*(n-i-1);
            s+=t;
            b=t;
        }
        cout<<s<<endl;
    }
    return 0;
}
