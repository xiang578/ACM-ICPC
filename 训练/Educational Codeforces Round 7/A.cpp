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
    ll n,a,l,r,mid,tmp,ans;
    cin>>n;
    l=1;
    r=1000000000;
    a=1;
    while(l<r)
    {
        mid=(l+r+1)/2;
        tmp=(1+mid)*mid/2;
        if(tmp>n) r=mid-1;
        else
        {
            a=mid;
            l=mid;
        }
    }
    ans=n-(1+a)*a/2;
    if(ans==0) ans=a;
    cout<<ans<<endl;
    return 0;
}
