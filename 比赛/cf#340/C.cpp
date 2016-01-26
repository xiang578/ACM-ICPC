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
struct node
{
    int n;
    ll r;
}p[N];

int cmp(node x,node y)
{
    return x.r>y.r;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n;
    ll a[N],x[N],y[N],a1,a2,b1,b2,ans,r1,r2;
    while(~scanf("%d",&n))
    {
        scanf("%lld%lld%lld%lld",&a1,&b1,&a2,&b2);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&x[i],&y[i]);
            a[i]=(x[i]-a1)*(x[i]-a1)+(y[i]-b1)*(y[i]-b1);
            p[i].n=i;
            p[i].r=(x[i]-a2)*(x[i]-a2)+(y[i]-b2)*(y[i]-b2);
        }
        p[n].r=0;
        p[n].n=n;
        sort(p,p+n,cmp);
        ans=r2=p[0].r;
        r1=0;
        for(i=0;i<n;i++)
        {
            r2=min(r2,p[i+1].r);
            r1=max(r1,a[p[i].n]);
            ans=min(ans,r1+r2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
