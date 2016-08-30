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
int n,m,a,x[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&a);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }
    if(n==1) {printf("0\n");return 0;}
    sort(x+1,x+n+1);
    ll ans=0;
    if(a<=x[1])
    {
        for(int i=2;i<n;i++)
        {
            ans+=x[i]-x[i-1];
        }
        ans+=x[1]-a;
    }
    else if(a>=x[n])
    {
        for(int i=3;i<=n;i++)
        {
            ans+=x[i]-x[i-1];
        }
        ans+=a-x[n];
    }
    else
    {
        int st;
        for(int i=2;i<=n;i++)
        {
            if(x[i-1]<a&&a<=x[i])
            {
                st=i;
                break;
            }
        }
        ll t1=0,t2=0;
        for(int i=2;i<st;i++)
        {
            t1+=x[i]-x[i-1];
        }
        t1+=a-x[st-1];
        for(int i=st;i<n;i++)
        {
            t2+=x[i+1]-x[i];
        }
        t2+=x[st]-a;
        ll a1,a2;
        if(st>=3)
        {
            a1=x[2]-x[1];
        }
        else
        {
            a1=a-x[st-1];
        }
        if(st==n)
        {
            a2=x[st]-a;
        }
        else
        {
            a2=x[n]-x[n-1];
        }
        ans=min((t1-a1)*2+t2,(t1-a1)+t2*2);
        ans=min(ans,min((t2-a2)*2+t1,(t2-a2)+t1*2));
        //rintf("%d %lld %lld %lld %lld\n",st,t1,a1,t2,a2);
    }
    printf("%lld\n",ans);
    return 0;
}
