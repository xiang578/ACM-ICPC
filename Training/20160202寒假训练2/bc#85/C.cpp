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
const ll inf=1e18;
const int N=1e5+10;
int p[N];
void init()
{
    memset(p,0,sizeof(p));
    p[1]=1;
    for(int i=2;i<N;i++)
    {
        if(p[i]) continue;
        for(int j=2*i;j<N;j+=i)
        {
            p[j]=1;
        }
    }
}

int ok(ll n)
{
    int t;
    ll up=sqrt(1.0*n)+1;
    for(ll i=2;i<=up;i++)
    {
        if(n%i==0)
        {
            t=0;
            while((n%i)==0)
            {
                t++;
                n/=i;
            }
            if(t>1) return 0;
        }
        if(n==0) break;
    }
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    ll n,x,y;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&n);
        if(n==1||n==2) {printf("%lld\n",2*2-n*n);continue;}
        x=(ll)sqrt(1.0*n);
        y=x+1;
        while(!ok(x)&&x>=2) x--;
        while(!ok(y)) y++;
        //printf("%lld %lld\n",x*x,y*y);
        printf("%lld\n",min(abs(n-x*x),abs(y*y-n)));
    }
    return 0;
}
