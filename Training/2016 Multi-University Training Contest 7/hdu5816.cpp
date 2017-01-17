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
const int N=(1<<20)+10;
int n,m,p,x[30],d[N];
ll dp[N],a[N],b[N],f[30];
ll gcd(ll n1,ll n2)
{
    if(n1==0) return n2;
    else return gcd(n2%n1,n1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    f[0]=1;
    for(int i=1; i<=20; i++)
        f[i]=f[i-1]*i;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&p,&n,&m);
        for(int i=0; i<m; i++)
            scanf("%d",x+i);
        int up=1<<(n+m);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<up; i++)
        {
            if(dp[i]==0) continue;
            d[i]=0;
            a[i]=b[i]=0;
            for(int j=0; j<m; j++)
            {
                int t=(1<<j);

                if(t&i)
                {
                    b[i]++;
                    d[i]+=x[j];
                }
            }

            for(int j=m; j<n+m; j++)
            {
                int t=(1<<j);
                if(t&i)
                {
                    a[i]++;
                }
            }
            int t=a[i]-b[i]+1;
            if(dp[i]==0||d[i]>=p) continue;
            if(t>0)
            {
                for(int j=0; j<m+n; j++)
                {
                    if((i&(1<<j))==0)
                    {
                        dp[i^(1<<j)]+=dp[i];
                    }
                }
            }
        }
        ll xx,yy;
        xx=0;
        yy=f[n+m];
        for(int i=0; i<up; i++)
        {
            if(d[i]<p) continue;
            xx+=dp[i]*f[n+m-a[i]-b[i]];
        }
        ll tmp=__gcd(xx,yy);
        if(xx==0) printf("0/1\n");
        else printf("%lld/%lld\n",xx/tmp,yy/tmp);
    }
    return 0;
}

