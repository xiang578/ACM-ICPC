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
const int N=1e5+10;
int n;
ll m,a[N];
vector<ll>ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    a[0]=0;
    a[n+1]=1e9;
    ans.clear();
    for(int i=1;i<=n+1;i++)
    {
        ll s=(a[i-1]+1+a[i]-1)*(a[i]-a[i-1]-1)/2;
        if(s<=m)
        {
            m-=s;
            for(ll j=a[i-1]+1;j<a[i];j++) ans.push_back(j);
        }
        else
        {
            ll l=a[i-1]+1,r=a[i]-1,mid,k,ss,st=a[i-1]+1;
            while(l<=r)
            {
                mid=(l+r)/2;
                s=(mid+st)*(mid-st+1)/2;
                //printf("%lld %lld %lld\n",l,mid,s);
                if(s<=m)
                {
                    k=mid;
                    ss=s;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            m-=ss;
            //cout<<ss<<endl;
            for(ll j=a[i-1]+1;j<=k;j++) ans.push_back(j);
            break;
        }
        if(m==0||m<a[i]+1) break;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%lld ",ans[i]);
    return  0;
}
