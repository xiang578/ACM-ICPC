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
typedef __int64 ll;
char s[1000000+10];
ll euler_phi(ll n)
{
    ll m=(ll)sqrt(n+0.5);
    ll ans=n;
    for(ll i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

ll pow_mod(ll a,ll n,ll m)
{
    if(n==0) return 1;
    ll x=pow_mod(a,n/2,m);
    ll ans=x*x%m;
    ans=ans%m;
    if(n%2==1) ans=ans*a%m;
    return ans;
}

int main()
{
    ll a,c,b,f;
    while(~scanf("%I64d",&a))
    {
        scanf("%s",s);
        scanf("%I64d",&c);
        f=euler_phi(c);
        int n=strlen(s);
        b=0;
        for(int i=0;i<n;i++)
        {
            b=b*10+s[i]-'0';
            b%=f;
        }
        b=b+f;
        printf("%lld\n",pow_mod(a,b,c));
    }
    return 0;
}
