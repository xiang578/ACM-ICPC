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
const ll mod=1e9+7;
const int N=2048;

ll a[1234567],b[1234567];

int cmp(ll x,ll y)
{
    return x>y;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll ans,tmp,cnt;
    int n,i,j,k;
    while(~scanf("%d",&n))
    {
        rep(i,0,n)
        scanf("%lld",&a[i]);
        rep(i,0,n)
        scanf("%lld",&b[i]);
        sort(a+1,a+n,cmp);
        sort(b,b+n);
        ans=0;

        rep(i,0,n)
        {
            tmp=1;
            cnt=0;
            k=0;
            rep(j,1,n)
            {
                while(k<n)
                {
                    if(k==i) k++;
                    if(a[j]*b[k]<a[0]*b[i]&&k<n)
                        cnt++,k++;
                    else
                        break;
                }
                tmp=(tmp*cnt)%mod;
                cnt--;
            }
            ans=(ans+tmp)%mod;
        }
        printf("%lld\n",ans);

    }
    return 0;
}
