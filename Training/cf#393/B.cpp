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
const int M=1e6+10;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,m,k,ans;
    cin>>n>>m>>k;
    m-=n;
    ans=0;
    ll l=0,r=m,mid;
    ll p=n-k+1;
    while(l<=r)
    {
        mid=(l+r)/2;
        ll tmp=0;
        //left
        if(mid<=k)
        {
            tmp=(1+mid)*mid/2;
        }
        else
        {
            tmp=(mid+mid-k+1)*k/2;
        }
        //right
        if(mid<=p)
        {
            tmp+=(1+mid)*mid/2;
        }
        else
        {
            tmp+=(mid+mid-p+1)*p/2;
        }
        tmp-=mid;
        //printf("%lld %lld\n",tmp,mid);
        if(tmp<=m)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}
